#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int b[maxn];
int n; ll k;
ll d(int i, ll x){//ax - x^3   - a*(x-1) + (x-1)^3
// -a - x^3 + (x^3 - 3x^2 + 3x -1)
// -a -3x^2 + 3x -1
    return a[i] - 3LL*x*x + 3*x -1;
}
bool check(ll lim){
    ll res = 0;
    for(int i = 1; i <= n; ++i){
        if(d(i,1) < lim){
            b[i] = 0; continue;
        }
        if(d(i, a[i]) >= lim){
            b[i] = a[i];
            res += a[i]; continue;
        }

        ll l = 0, r = a[i];
        ll t = 10086;
        while(l <= r){
            if(d(i,mid) >= lim) t = mid, l = mid+1;
            else r = mid-1;
        }
        assert(t != 100866);
        b[i] = t;
        res += t;
    }
    return res >= k;

}
int main()
{
    scanf("%d%lld", &n, &k);
    fors(i,1,n+1) scanf("%d", &a[i]);
    ll l = -4*1e18, r = 1e9+1;
    ll ans = 10086;
    while(l <= r){
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    //cout<<ans<<endl;
    assert(check(ans));

    ll sum = 0;
    fors(i,1,n+1) {
        sum+=b[i];
        //cout<<"i:"<<i<<" d:"<<-3LL*b[i]*b[i]-3LL*b[i]-1 + a[i]<<endl;
    }
    //cout<<sum<<endl;
    fors(i,1,n+1){
        if(sum > k && b[i] > 0 && d(i, b[i]) == ans) sum--, b[i]--;
    }
    fors(i,1,n+1){
        printf("%d ", b[i]);
    }
}