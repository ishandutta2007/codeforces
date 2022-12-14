#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

const int MAXN = 105;

int n;
char s[MAXN];
int a[MAXN][MAXN], was[MAXN][MAXN], bit[MAXN][MAXN];
vector <pair <int, int> > v;

bool good(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
        return 1;
    return 0;
}

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        gets(s);
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '.')
                a[i][j] = 0;
            if (s[j] == 'x')
                a[i][j] = 1;
            if (s[j] == 'o')
                a[i][j] = 2;                
            if (a[i][j] == 2)
                v.pb(mp(i, j));
        }
    }
    for (int dx = -(n - 1); dx < n; dx++)
        for (int dy = -(n - 1); dy < n; dy++)
        {
            was[n - 1 + dx][n - 1 + dy] = 1;
            for (int i = 0; i < (int) v.size(); i++)
                if (good(v[i].first + dx, v[i].second + dy) && a[v[i].first + dx][v[i].second + dy] == 0)
                    was[n - 1 + dx][n - 1 + dy] = 0;    
            if (was[n - 1 + dx][n - 1 + dy])
            {
                for (int i = 0; i < (int) v.size(); i++)
                    if (good(v[i].first + dx, v[i].second + dy))
                        bit[v[i].first + dx][v[i].second + dy] = 1;    
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1 && !bit[i][j])
            {
                puts("NO");
                return 0;
            }
    puts("YES");
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j ++)
        {
            if (i == n - 1 && j == n - 1)
            {
                printf("o");
                continue;
            }
            if (was[i][j])
                printf("x");
            else
                printf(".");
        }
        puts("");
    }
    return 0;
}