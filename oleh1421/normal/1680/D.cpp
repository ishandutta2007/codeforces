//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500010;
const ll inf=2e18;
const ll mod=1000000007;
ll a[N];
ll pref[N];
int cnt[N];
void solve(int Case){
    int n;cin>>n;
    ll k;cin>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
        cnt[i]=cnt[i-1]+(a[i]==0);
    }
    ll res=-2;
    for (int l=1;l<=n;l++){
        for (int r=l;r<=n;r++){
            ll cn=cnt[r]-cnt[l-1];
            ll sum=pref[r]-pref[l-1];
            ll cn1=cnt[n]-cn;
            ll mx=cn*k;
            mx=min(mx,k*cn1-pref[n]);
            if (mx+pref[n]>=(-k)*cn1 && mx>=-cn*k) res=max(res,sum+mx);
            ll mn=-cn*k;
            mn=max(mn,-k*cn1-pref[n]);
            if (mn+pref[n]<=k*cn1 && mn<=cn*k) res=max(res,-sum-mn);
        }
    }
    cout<<res+1<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;

    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/