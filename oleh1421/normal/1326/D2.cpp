//#pragma GCC opitmize ("trapv")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1000000017ll;
const int N=1000000;
ll p[N+10];
ll pref[N+10];
ll suf[N+10];
int n;
ll get1(int l,int r){
    return ((pref[r]-pref[l-1]+mod)*p[n-r+1])%mod;
}
ll get2(int l,int r){
    return ((suf[l]-suf[r+1]+mod)*p[l])%mod;
}
void solve(){
    string s;cin>>s;
    n=s.size();
    pref[0]=0ll;
    for (int i=0;i<n;i++){
        pref[i+1]=((s[i]-'a'+1ll)*p[i]+pref[i])%mod;
    }
    suf[n+1]=0ll;
    for (int i=n;i>=1;i--){
        suf[i]=((s[i-1]-'a'+1ll)*p[n-i]+suf[i+1])%mod;
    }
    int len=0;
    while (len<n && s[len]==s[n-len-1]) len++;
    if (len==n){
        cout<<s<<endl;
        return;
    }
    int mxa=0;
    for (int i=1;i<=n-len*2;i++){
        if (get1(len+1,len+i)==get2(len+1,len+i)) {
            mxa=i;
        }
    }
    int mxb=0;
    for (int i=1;i<=n-2*len;i++){
        if (get1(n-len-i+1,n-len)==get2(n-len-i+1,n-len)) mxb=i;
    }
    string res="";
    for (int i=0;i<len;i++) res+=s[i];
    if (mxa>mxb){
        for (int i=0;i<mxa;i++) res+=s[i+len];
    } else {
        for (int i=mxb-1;i>=0;i--) res+=s[n-len-1-i];
    }
    for (int i=len;i>=1;i--) res+=s[n-i];
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    p[0]=1ll;
    for (int i=1;i<=N;i++){
        p[i]=(p[i-1]*29ll)%mod;
    }
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
rzjjebcgotjffuzr
rzjjotjffuzr
*/