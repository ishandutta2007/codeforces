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

const int MAXN = 1e4;

string s[3], a[10];
char str[MAXN], cur[MAXN];
int p[10];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    forn (i, 3)
    {
        string t, r = "";
        cin >> t;
        int n = t.length();
        forn (i, n)
        {
            if (t[i] >= 'A' && t[i] <= 'Z')
                t[i] = t[i] - 'A' + 'a';
            if (t[i] >= 'a' && t[i] <= 'z')
                r += t[i];
        }
        s[i] = r;
    }
    forn (i, 3)
        p[i] = i;
    int cnt = 0;
    do
    {
        a[cnt++] = s[p[0]] + s[p[1]] + s[p[2]];
    }
    while (next_permutation(p, p + 3));
    int n;
    scanf("%d\n", &n);
    forn (k, n)
    {
        gets(str);
        int len = strlen(str);
        int pos = 0;
        forn (i, len)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
            if (str[i] >= 'a' && str[i] <= 'z')
                cur[pos++] = str[i];
        }
        bool was = 0;
        forn (j, 6)
        {
            bool ok = 1;
            if (pos == (int) a[j].length())
            {
                forn (i, pos)
                    if (a[j][i] != cur[i])
                        ok = 0;
            } 
            else
                ok = 0;
            was = max(was, ok);
        }
        if (was)
            puts("ACC");
        else
            puts("WA");
    }
    return 0;
}