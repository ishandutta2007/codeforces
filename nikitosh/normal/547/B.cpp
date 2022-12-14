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

const int MAXN = 2e5 + 5;

int a[MAXN], Left[MAXN], Right[MAXN], ans[MAXN];
pair <int, int> st[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int sz = 0;
    for (int i = 0; i < n + 2; i++)
    {
        while (sz > 0 && a[i] <= st[sz - 1].first)
            sz--;
        if (sz > 0)
            Left[i] = st[sz - 1].second;
        st[sz++] = mp(a[i], i);
    } 
    sz = 0;
    for (int i = n + 1; i >= 0; i--)
    {
        while (sz > 0 && a[i] <= st[sz - 1].first)
            sz--;
        if (sz > 0)
            Right[i] = st[sz - 1].second;
        st[sz++] = mp(a[i], i);
    } 
    for (int i = 1; i <= n; i++)
    {
        int k = Right[i] - Left[i] - 1;
        ans[k] = max(ans[k], a[i]);
    }
    int cur = 0;
    for (int i = n; i > 0; i--)
    {
        cur = max(cur, ans[i]);
        ans[i] = cur;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}