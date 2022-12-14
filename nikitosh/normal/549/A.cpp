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

const int MAXN = 200;

char s[MAXN][MAXN];
vector <char> v;

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n, m, ans = 0;
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
        gets(s[i]);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            v.clear();
            v.pb(s[i][j]);
            v.pb(s[i + 1][j]);
            v.pb(s[i][j + 1]);
            v.pb(s[i + 1][j + 1]);
            sort(v.begin(), v.end());
            if (v[0] == 'a' && v[1] == 'c' && v[2] == 'e' && v[3] == 'f')
                ans++;
        }
    printf("%d\n", ans);
    return 0;
}