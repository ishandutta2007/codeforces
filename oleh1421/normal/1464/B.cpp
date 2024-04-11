//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
ll pref[N];
ll suf[N];
ll cnt0[N],cnt1[N];
ll get(string s,ll x,ll y){
    int n=s.size();
    cnt0[0]=0;
    for (int i=1;i<=n;i++) cnt0[i]=cnt0[i-1]+(s[i-1]=='0');
    cnt1[0]=0;
    for (int i=1;i<=n;i++) cnt1[i]=cnt1[i-1]+(s[i-1]=='1');
    pref[0]=0;
    for (int i=0;i<n;i++){
        if (s[i]=='?' || s[i]=='0') pref[i+1]=pref[i]+cnt1[i]*y;
        else pref[i+1]=pref[i]+(i-cnt1[i])*x;
    }
    ll val=0ll;
    ll res=pref[n];
//    cout<<res<<endl;
    for (ll i=n-1;i>=0;i--){
        if (s[i]=='?' || s[i]=='1') val+=(cnt0[n]-cnt0[i])*y;
        else val+=(n-i-(cnt0[n]-cnt0[i]))*x;

        ll cur=val+pref[i]+(i-cnt1[i])*(n-i-(cnt0[n]-cnt0[i]))*x+cnt1[i]*(cnt0[n]-cnt0[i])*y;
//        if (cur==54){
//            cout<<"OK "<<i<<" "<<pref[i]<<" "<<endl;
//        }
        res=min(res,cur);
    }
    return res;
}
void solve(){
    string s;cin>>s;
    int x,y;cin>>x>>y;
    ll res=get(s,x,y);
    for (int i=0;i<s.size();i++){
        if (s[i]=='0') s[i]='1';
        else if (s[i]=='1') s[i]='0';
    }
    swap(x,y);
    cout<<min(res,get(s,x,y))<<endl;

//    int n,m;cin>>n>>m;
//    for (int i=0;i<=n;i++) r[i]=c[i]=0,used[i]=0;
//    int res=m;
//    for (int i=1;i<=m;i++) cin>>x[i]>>y[i],r[x[i]]=i,c[y[i]]=i,res-=(x[i]==y[i]);
//    for (int i=1;i<=m;i++) p[i]=r[y[i]];
//
//    for (int i=1;i<=m;i++){
//        if (used[i] || p[i]==i) continue;
//        int x=i;
//        while (!used[x] && x){
//            used[x]=true;
//            x=p[x];
//        }
//        if (x) res++;
//    }
//    cout<<res<<endl;
//    int res=m;
//    for (int i=1;i<=n;i++){
//        res-=(r[i]==0 && c[i]==0);
//    }
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