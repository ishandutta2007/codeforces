#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 3e5 + 50;
const int inf = 0x3f3f3f3f;
int n;
int x[maxn];
int l[maxn], r[maxn];
void init(){
    scanf("%d", &n); for(int i = 1; i <= n; ++i) l[i] = inf, r[i] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x[i]); l[x[i]] = min(l[x[i]],i); r[x[i]] = i;
    }
}
int dp[maxn];
void sol(){
    sort(x+1,x+1+n);
    n = unique(x+1,x+1+n)-x-1;
    dp[1] = 1;
    int ans = 1;
    for(int i = 2; i <= n; ++i){
        if(l[x[i]] > r[x[i-1]]) dp[i] = dp[i-1]+1;
        else dp[i] = 1;
        ans = max(ans, dp[i]);
    }
    printf("%d\n", n-ans);
}
int main()
{
    int T; cin>>T;
    while(T--){
        init(); sol();
    }
}