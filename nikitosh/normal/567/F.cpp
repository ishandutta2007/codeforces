#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 120;

map <int, LL> d[MAXN];
int a[MAXN], b[MAXN], type[MAXN];
char ch[MAXN][5];
int k;

LL dp(int n, int before)
{
    if (n == 0)
        return 1;
    if (d[n].count(before))
        return d[n][before];
    LL curAns = 0;
    bool flag;
    
    flag = 1;
    for (int i = 0; i < k; i++)
    {
        if (a[i] <= before || b[i] <= before || a[i] > 2 * n + before || b[i] > 2 * n + before)
            continue;
        if (a[i] == 2 * n + before || a[i] == 2 * n + before - 1)
        {
            if (type[i] == 2 || type[i] == 3)
                flag = 0;
        }
        if (b[i] == 2 * n + before || b[i] == 2 * n + before - 1)
        {
            if ((type[i] == 1 || type[i] == 4) && a[i] != 2 * n + before - 1 && a[i] != 2 * n + before)
                flag = 0;
            if (type[i] == 2)
                flag = 0;
        }
    }
    if (flag)
        curAns += dp(n - 1, before);

    flag = 1;
    for (int i = 0; i < k; i++)
    {
        if (a[i] <= before || b[i] <= before || a[i] > 2 * n + before || b[i] > 2 * n + before)
            continue;
        if (b[i] == before + 1 || b[i] == before + 2)
        {
            if (type[i] == 2 || type[i] == 3)
                flag = 0;
        }
        if (a[i] == before + 1 || a[i] == before + 2)
        {
            if ((type[i] == 1 || type[i] == 5) && b[i] != before + 1 && b[i] != before + 2)
                flag = 0;
            if (type[i] == 3)
                flag = 0;
        }
    }
    if (flag)
        curAns += dp(n - 1, before + 2);

    flag = 1;
    for (int i = 0; i < k; i++)
    {
        if (a[i] <= before || b[i] <= before || a[i] > 2 * n + before || b[i] > 2 * n + before)
            continue;
        if (a[i] == before + 1)
        {
            if ((type[i] == 1 || type[i] == 5) && b[i] != before + 1 && b[i] != 2 * n + before)
                flag = 0;
            if (type[i] == 3)
                flag = 0;
        }
        if (a[i] == 2 * n + before)
        {
            if (type[i] == 2 || type[i] == 3)
                flag = 0;
        }
        if (b[i] == 2 * n + before)
        {
            if ((type[i] == 1 || type[i] == 4) && a[i] != before + 1 && a[i] != 2 * n + before)
                flag = 0;
            if (type[i] == 2)
                flag = 0;
        }
        if (b[i] == before + 1)
        {
            if (type[i] == 2 || type[i] == 3)
                flag = 0;
        }
        if (a[i] == before + 1 && b[i] == 2 * n + before && (type[i] == 2 || type[i] == 3))
            flag = 0;
    }
    if (flag)
        curAns += dp(n - 1, before + 1);
    if (n == 1)
        curAns = min(curAns, 1ll);
    //printf("%d %d %I64d\n", n, before, curAns);
    return d[n][before] = curAns;

}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d%d", &n, &k);
    forn (i, k)
    {
        scanf("%d %s %d", &a[i], ch[i], &b[i]);
        if (strlen(ch[i]) == 1)
        {
            if (ch[i][0] == '=')
                type[i] = 1;
            if (ch[i][0] == '<')
                type[i] = 2;
            if (ch[i][0] == '>')
                type[i] = 3;
        }
        else
        {
            if (ch[i][0] == '<')
                type[i] = 4;
            if (ch[i][0] == '>')
                type[i] = 5;
        }
        if (a[i] == b[i] && (type[i] == 2 || type[i] == 3))
        {
            puts("0");
            return 0;
        }
        if (a[i] > b[i])
        {
            if (type[i] >= 2 && type[i] <= 3)
                type[i] = 5 - type[i];
            if (type[i] >= 4 && type[i] <= 5)
                type[i] = 9 - type[i];
            swap(a[i], b[i]);
        }
    }
    printf("%I64d\n", dp(n, 0));
    return 0;
}