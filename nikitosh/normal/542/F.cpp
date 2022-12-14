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

const int MAXN = 1005;

int last[MAXN];
vector <int> c[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int N, T;
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++)
    {
        int t, q;
        scanf("%d%d", &t, &q);
        c[T - t].pb(q);
    }    
    for (int i = T; i > 0; i--)
    {
        sort(c[i].begin(), c[i].end());
        //printf("%d\n", last[i]);
        for (int j = c[i].size() - 1; j > 0; j -= 2)
        {
            int cur = c[i][j] + c[i][j - 1];
            c[i - 1].pb(cur);
        }
        if (c[i].size() % 2 == 1)
            c[i - 1].pb(c[i][0]); 
    }
    sort(c[0].begin(), c[0].end());
    reverse(c[0].begin(), c[0].end());
    int ans = 0;
    ans = c[0][0];
    printf("%d\n", ans);
    return 0;
}