#include <bits/stdc++.h>
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=200010;
const int TSZ=1e7;
const ll inf=1e18;
const ll mod=998244353;
ll a[N];
ll pref[N];
ll suf[N];
ll f[N],rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll C(int n,int k){
    if (k>n || k<0) return 0;
    return f[n]*rf[n-k]%mod*rf[k]%mod;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],pref[i]=pref[i-1]+a[i];
    for (int i=1;i<=n+1;i++) suf[i]=pref[n]-pref[i-1];
    vector<pair<int,int> >v;
    int l=1,r=n;
    int X=-1;
    while (l<r){
        if (pref[l]<suf[r]) l++;
        else if (pref[l]>suf[r]) r--;
        else {
            if (pref[l]*2==pref[n]){
                X=r-l+1;
                break;
            } else {
                int cnt1=1;
                while (pref[l+1]==pref[l]){
                    cnt1++;
                    l++;
                }
                int cnt2=1;
                while (suf[r-1]==suf[r]){
                    cnt2++;
                    r--;
                }
                v.push_back({cnt1,cnt2});
                l++;
                r--;
            }
        }
//        cout<<l<<" "<<r<<endl;
    }

    ll res=1ll;
    if (X!=-1){
        res=binpow(2,X-1);
    }
    for (auto cur:v){
        int x=cur.first;
        int y=cur.second;
        ll sum=0ll;
        for (int i=0;i<=min(x,y);i++){
            sum+=C(x,i)*C(y,i);
            sum%=mod;
        }
        res*=sum;
        res%=mod;
    }

    cout<<res<<'\n';

}
int main() {
    f[0]=1;
    for (int i=1;i<N;i++) f[i]=(f[i-1]*i)%mod;
    rf[N-1]=binpow(f[N-1],mod-2);
    for (int i=N-1;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}