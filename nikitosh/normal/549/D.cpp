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

const int MAXN = 205;

LL a[MAXN][MAXN], c[MAXN][MAXN];
char s[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n, m, ans = 0;
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        gets(s);
        for (int j = 0; j < m; j++)
            if (s[j] == 'W')
                a[i][j] = 1;
            else
                a[i][j] = -1;
    } 
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            if (c[i][j] != a[i][j])
            {
                ans++;
                LL dlt = a[i][j] - c[i][j];
                for (int x = 0; x <= i; x++)
                    for (int y = 0; y <= j; y++)
                        c[x][y] += dlt;
            }
    printf("%d\n", ans);
    return 0;
}