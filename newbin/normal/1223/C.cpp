#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
ll x, y, a, b;
int n;
ll k;
ll p[maxn], sum[maxn];
bool check(int lim){
    int v = lim/( a/__gcd(a,b)*b );//,ll
    int t1 = lim/a - v;
    int t2 = lim/b - v;
    ll ans = 0;
    ans += (ll)(x+y)*sum[v];
    ans += (ll)x*(sum[v+t1]-sum[v]);
    ans += (ll)y*(sum[v+t1+t2]-sum[v+t1]);
    return ans >= k;
}
int main()
{
    int T;cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", &p[i]); p[i]/=100;
        }
        cin>>x>>a>>y>>b;
        if(y > x) swap(x,y), swap(a,b);//x >= y
        cin>>k;
        sort(p+1,p+1+n);
        reverse(p+1,p+1+n);
        sum[0] = 0;
        for(int i =1; i <= n; ++i) {
            //cout<<"i:"<<i<<" pi:"<<p[i]<<endl;
            sum[i] = sum[i-1]+p[i];
        }

        int l = 1, r = n;
        int ans = -1;
        while(l <= r){
            if(check(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        printf("%d\n", ans);
    }
}