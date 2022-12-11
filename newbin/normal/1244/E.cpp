#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5 + 50;
ll cc[maxn];
ll a[maxn], sum[maxn], sz[maxn];
int num;
int n; ll k;
bool check(ll len){
    ll r = cc[1], l = r-len;
    int lp = 1, rp = 1;
    ll ans = k+1;
    while(1){
//        if(len == 0){
//            cout<<"l:"<<l<<" r:"<<r<<endl;
//        }
        ll res1 = l*sz[lp-1] - sum[lp-1];
        ll res2 = (sum[num] - sum[rp]) - r*(sz[num] - sz[rp]);
        ans = min(ans, res1 + res2);
//        if(len == 0) cout<<ans<<endl;
        if(rp >= num) break;
        if(cc[rp+1] - r <= cc[lp] - l){
            rp++;
            r = cc[rp];
            l = r-len;
        }
        else{
            l = cc[lp];
            r = l + len;
            lp++;
        }
    }
    return ans <= k;
}
int main()
{
    cin>>n>>k;
    for(int i = 1; i <= n; ++i) scanf("%I64d", &a[i]), cc[++num] = a[i];
    sort(cc+1,cc+1+num); num = unique(cc+1,cc+1+num)-cc-1;
    for(int i = 1; i <= n; ++i){
        int p = lower_bound(cc+1,cc+1+num, a[i])-cc;
        sz[p]++;
    }
    for(int i = 1; i <= num; ++i){
        sum[i] = sum[i-1] + cc[i]*sz[i];
        sz[i] += sz[i-1];
    }
    //sun[num+1] = sum[num]; sz[num+1] = sz[num];
    ll l = 0, r = 1e15, ans;
    while(l <= r){
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    printf("%I64d\n", ans);
}