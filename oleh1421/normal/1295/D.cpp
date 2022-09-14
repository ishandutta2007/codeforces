//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//const ll mod=1000000007ll;
using namespace std;
#define endl '\n'
const int N=200010;
const int L=31;
vector<ll>p;
vector<int>l;
ll a,m;
ll res=0ll;
ll f(ll l,ll r,ll d){
    return (r/d)-((l-1)/d);
}
void F(int pos,int cnt,ll d){
    if (pos==p.size()){
        if (cnt%2) {
            res-=f(a,m+a-1ll,d);
            //cout<<"- "<<d<<endl;
        }
        else {
            res+=f(a,m+a-1ll,d);
           // cout<<"+ "<<d<<endl;
        }
        return;
    }
    for (int i=0;i<=1;i++){
        F(pos+1,cnt+i,d);
        d*=p[pos];
    }
}
void solve(){
    cin>>a>>m;
    ll g=__gcd(a,m);
    a/=g;
    m/=g;
    ll d=2ll;
    ll x=m;
    p.clear();
    l.clear();
    while (d*d<=x){
        int cnt=0;
        while (x%d==0){
            x/=d;
            cnt++;
        }
        if (cnt){
            p.push_back(d);
            l.push_back(cnt);
        }
        d++;
    }
    if (x>1){
        p.push_back(x);
        l.push_back(1);
    }
    res=0ll;
    F(0,0,1ll);
    cout<<res<<endl;
//    int cnt=0;
//    for (int i=a;i<a+m;i++){
//        cnt+=(__gcd(i*1ll,m)==1);
//    }
//    cout<<cnt<<endl;
}
int32_t main()
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