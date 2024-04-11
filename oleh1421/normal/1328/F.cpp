//#pragma GCC opitmize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
int b[N];
int r[N];
map<int,int>cnt;
ll pref[N];
ll suf[N];
void solve(){
    int n,k;cin>>n>>k;
    int mx=0;
    int mn=1000000001;
    cnt.clear();
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
        cnt[a[i]]++;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        if (cnt[a[i]]>=k){
            cout<<0<<endl;
            return;
        }
    }
    pref[0]=0ll;
    for (int i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    suf[n+1]=0ll;
    for (int i=n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
    }
    ll res=1000000000000000001ll;
    for (int i=1;i<n;i++){
        if (a[i]==a[i+1]) continue;
        ll cur=max(0,k-cnt[a[i+1]]);
        if (i>=cur){
            res=min(res,(a[i]*1ll)*(i*1ll)-pref[i]+(i*1ll)*(a[i+1]-a[i]-1ll)+cur);
        }
    }
    for (int i=n;i>1;i--){
        if (a[i]==a[i-1]) continue;
        ll cur=max(0,k-cnt[a[i-1]]);
        if (n-i+1>=cur){
            res=min(res,suf[i]-(a[i]*1ll)*((n-i+1ll))+(n-i+1ll)*(a[i]-a[i-1]-1ll)+cur);
        }
    }
    for (int i=1;i<n;i++){
        if (a[i]==a[i+1]) continue;
        ll cn=cnt[a[i]];
        ll cur=k-cn;
        ll pr=(a[i]-1ll)*(i-cn)-pref[i-cn];
        ll sf=suf[i+1]-(a[i]+1ll)*(n-i+0ll);
        res=min(res,cur+pr+sf);
    }
    cout<<res<<endl;
//    if (mx-mn==2){
//        ll cnt=0;
//        for (int i=1;i<=n;i++){
//            cnt+=(a[i]==mn+1);
//        }
//        res=min(res,max(k*1ll-cnt,0ll));
//    } else if (mx-mx==1){
//        int cnt1=0;
//        int cnt2=0;
//        for (int i=1;i<=n;i++){
//            cnt1+=(mn==a[i]);
//            cnt2+=(mx==a[i]);
//        }
//        res=min(res,max(k*1ll-max(cnt1,cnt2)*1ll,0ll));
//    }
//    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/*
10 7
1 1 1 3 3 3 35 40 40 40
*/