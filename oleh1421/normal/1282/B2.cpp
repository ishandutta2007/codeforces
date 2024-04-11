#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
vector<ll> cnt[300001];
void solve(){
    ll n,k,p;cin>>n>>p>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=k;i++) cnt[i].clear();
    sort(a+1,a+n+1);
    for (int i=0;i<k;i++){
        ll cur=0ll;
        cnt[i].push_back(cur);
        for (int j=i+k;j<=n;j+=k){
            cur+=a[j];
            cnt[i].push_back(cur);
        }
    }
    ll res=0;
    ll cur=0;
    for (int i=0;i<k;i++){
        cur+=a[i];
        int ost=i;
        int pos=upper_bound(cnt[ost].begin(),cnt[ost].end(),p-cur)-cnt[ost].begin()-1;
        //cout<<i<<" "<<i+pos*k<<endl;
        res=max(res,i+pos*k);
    }
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}