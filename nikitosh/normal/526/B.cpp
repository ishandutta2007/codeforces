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

int n, a[10005], ans[10005];
pair <int, int> gr[10005];

void build (int v, int l, int r)
{
    gr[v] = mp(l, r);
    if (l == r - 1)
        return;
    int m = (l + r) / 2;
    build(2 * v + 2, l, m);   
    build(2 * v + 3, m, r);   
}

int main() {
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d", &n);
    for (int i = 0; i < (1 << (n + 1)) - 2; i++)
        scanf("%d", &a[i]);
    build(0, 0, (1 << (n - 1)));
    build(1, (1 << (n - 1)), 1 << n);
    int N = (1 << n);
    int max1 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 2; j++)
            if (i >= gr[j].first && i < gr[j].second)
                ans[i] += a[j];
        max1 = max(max1, ans[i]);
    }
    int Ans = 0;
    for (int j = 0; j < 2 * N - 2; j++)
    {
        int Max = 0;
        for (int i = gr[j].first; i < gr[j].second; i++)
            Max = max(Max, ans[i]);
        for (int i = gr[j].first; i < gr[j].second; i++)
            ans[i] += max1 - Max;
        Ans += max1 - Max;
    }        
    printf("%d\n", Ans);
    return 0;
}