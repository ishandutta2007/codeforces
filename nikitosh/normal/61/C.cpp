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

const int MAXN = 1e5;

char s[MAXN], t[MAXN], cnt[MAXN];
vi v, ans, rightAns;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int a;
    scanf("%d ", &a);
    gets(s);
    gets(t);
    LL val = 0, n = strlen(t);
    forn (i, n)
    {
        if (t[i] >= '0' && t[i] <= '9')
            val = val * a + t[i] - '0';
        else
            val = val * a + t[i] - 'A' + 10;
    }
    if (s[0] == 'R')
    {
        vector <pair <int, char> > values = {mp(1, 'I'), mp(5, 'V'), mp(10, 'X'), mp(50, 'L'), mp(100, 'C'), mp(500, 'D'), mp(1000, 'M')};
        fornr (i, sz(values))
        {
            int k = values[i].fs;
            if (val >= k)
            {
                if (val >= 4 * k)
                    ans.pb(i), ans.pb(i + 1), val -= 4 * k;
                else
                    while (val >= k)
                        ans.pb(i), val -= k;
            }
        }

        //forn (i, sz(ans))
        //    printf("%d ", ans[i]);
        forn (i, sz(ans))
        {
            int k = ans[i];
            cnt[k]++;
            if ((k % 2 == 1 && cnt[k] > 1) || (k % 2 == 0 && cnt[k] > 4))
            {
                int l = rightAns.back();
                rightAns.pop_back();
                while (rightAns.back() == k)
                    rightAns.pop_back();
                rightAns.push_back(l);
                ans[i] = k + 1;
                cnt[k]--;
                i--;    
            }
            else
                rightAns.pb(k);
        }
        for (auto k : rightAns)
            printf("%c", values[k].sc);
        puts("");
    }
    else
    {
        int b;
        sscanf(s, "%d", &b);
        while (val > 0)
        {
            v.pb(val % b);
            val /= b;
        }
        reverse(all(v));
        for (auto k : v)
        {
            if (k < 10)
                printf("%d", k);
            else
                printf("%c", 'A' + k - 10);
        }
        if (sz(v) == 0)
            printf("0");
        puts("");
    }
    return 0;
}