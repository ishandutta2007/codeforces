//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=10010;
ll a[N];
ll pref[N];
ll L[N],R[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    pref[0]=0;
    for (int i=1;i<=n;i++){
        pref[i]=pref[i-1];
        ll mn=a[i];
        for (int j=i;j>=1;j--){
            mn=min(mn,a[j]);
            pref[i]=max(pref[i],(i-j+1ll)*mn);
        }
    }
    ll res=0ll;
    for (int l=1;l<=n;l++){
        ll mn=a[l];
        for (int r=l;r<=n;r++){
            mn=min(mn,a[r]);
            res=max(res,pref[l-1]+mn*(r-l+1ll));
            res=max(res,(mn-1)*(r-l+1ll)+n);
        }
    }
    for (int i=1;i<=n;i++){
        int l=i,r=i;
        while (l>=1 && a[l]>=a[i]) l--;
        l++;
        while (r<=n && a[r]>=a[i]) r++;
        r--;
        L[i]=l;
        R[i]=r;
        vector<ll>mnR,mnL;
        ll cur=a[i];
        for (int j=r;j<=n;j++) {
            cur=min(cur,a[j]);
            mnR.push_back(cur);
        }
        cur=a[i];
        for (int j=l;j>=1;j--){
            cur=min(cur,a[j]);
            mnL.push_back(cur);
        }
        ll len=r-l+1ll;
        {
        ll ind=0;
        vector<ll>suf(mnR.size()+1,0);
        for (ll i=(int)mnR.size()-1;i>=0;i--){
            suf[i]=max(suf[i+1],mnR[i]*(len+i));
        }
        for (ll j=(int)mnL.size()-1;j>=0;j--){
            while (ind<mnR.size() && mnR[ind]+mnL[j]>=a[i]) ind++;
            if (ind){
                ll t=ind-1;
                res=max(res,min(mnL[j]+mnR[t],a[i])*len+j*mnL[j]+t*min(mnR[t],a[i]-mnL[j]));
            }
            res=max(res,mnL[j]*len+j*mnL[j]+suf[ind]);
        }
        }
        swap(mnL,mnR);
        {
        ll ind=0;
        vector<ll>suf(mnR.size()+1,0);
        for (ll i=(int)mnR.size()-1;i>=0;i--){
            suf[i]=max(suf[i+1],mnR[i]*(len+i));
        }
        for (ll j=(int)mnL.size()-1;j>=0;j--){
            while (ind<mnR.size() && mnR[ind]+mnL[j]>=a[i]) ind++;
            if (ind){
                ll t=ind-1;
                res=max(res,min(mnL[j]+mnR[t],a[i])*len+j*mnL[j]+t*min(mnR[t],a[i]-mnL[j]));
            }
            res=max(res,mnL[j]*len+j*mnL[j]+suf[ind]);
        }
        }
    }
    for (ll i=1;i<=n;i++){
        for (ll j=L[i];j<=R[i];j++){
            res=max(res,(R[j]-L[j]+1)*(a[j]-a[i])+a[i]*(R[i]-L[i]+1));
        }
    }
    cout<<res<<endl;


}

int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;

    while (tt--){
        solve();
    }
    return 0;
}

/**
1
4 2
1 2
1 3
1 4
**/