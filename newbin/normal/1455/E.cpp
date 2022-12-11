#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
ll x[4], y[4];
vector<ll> p;
int a[4] = {0,1,2,3};
ll xx[4], yy[4];
ll cal(ll l){
    if(l < 0) return 1e18;
    p.clear();
    p.pb(x[a[0]]); p.pb(x[a[1]]); p.pb(x[a[2]]-l); p.pb(x[a[3]]-l);
    sort(p.begin(), p.end());
    ll cx = p[1];
    ll mx = 0;
    fors(i,0,4) mx += abs(p[1]-p[i]);

    p.clear();
    p.pb(y[a[0]]); p.pb(y[a[1]]-l); p.pb(y[a[2]]); p.pb(y[a[3]]-l);
    sort(p.begin(), p.end());
    ll cy = p[1];
    ll my = 0;
    fors(i,0,4) my += abs(p[1]-p[i]);
    //cout<<"l:"<<l<<"mx:"<<mx<<" my:"<<my<<endl;
    return mx+my;
}
int main()
{
    int T; cin>>T;
    while(T--){
        fors(i,0,4) scanf("%lld%lld", &x[i], &y[i]);
        ll ans = 1e18;
        do{
            ans = min(ans, cal(x[a[2]]-x[a[0]]));
            ans = min(ans, cal(x[a[3]]-x[a[0]]));
            ans = min(ans, cal(x[a[2]]-x[a[1]]));
            ans = min(ans, cal(x[a[3]]-x[a[1]]));

            ans = min(ans, cal(y[a[1]]-y[a[0]]));
            ans = min(ans, cal(y[a[3]]-y[a[0]]));
            ans = min(ans, cal(y[a[1]]-y[a[2]]));
            ans = min(ans, cal(y[a[3]]-y[a[2]]));
        }while(next_permutation(a,a+4));
        printf("%lld\n", ans);
    }
}