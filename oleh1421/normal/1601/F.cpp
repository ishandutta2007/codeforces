//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
const ll mod=1000000007;
const ll mod1=998244353;
ll n;
vector<int>to_vec(ll x){
    vector<int>v;
    while (x){
        v.push_back(x%10);
        x/=10;
    }
    reverse(v.begin(),v.end());
    if (v.empty()) v.push_back(0);
    return v;
}
vector<int>vn;
ll calc_pos(ll x){
    vector<int>v=to_vec(x);
    ll res=0ll;
    for (int i=0;i<v.size();i++){
        res++;
        for (int d=(i==0);d<v[i];d++){
            ll pw=1ll;
            for (int len=0;len<(int)vn.size()-i-1;len++){
                res+=pw;
                pw*=10ll;
            }
            int cmp=0;
            for (int j=0;j<i;j++){
                if (v[j]==vn[j]) continue;
                if (v[j]>vn[j]) cmp=1;
                else cmp=-1;
                break;
            }
            if (cmp==0){
                if (d>vn[i]) cmp=1;
                else if (d<vn[i]) cmp=-1;
            }
            if (cmp==1) continue;
            if (cmp==-1){
                res+=pw;
                continue;
            }
            ll add=0ll;
            for (int j=i+1;j<vn.size();j++) add=(add*10ll+vn[j]);
            res+=add+1ll;
        }
    }
    return res;
}
ll bin_search(ll L,ll R,ll diff){
    if (L>R) return 0;
    ll p=L-1;
    for (int i=40;i>=0;i--){
        if (p+(1ll<<i)<=R && calc_pos(p+(1ll<<i))-p-(1ll<<i)<=diff) p+=(1ll<<i);
    }
    return p-L+1ll;
}
void solve(){
    cin>>n;
    vn=to_vec(n);
    ll pw=1ll;
    ll res=0ll;
    for (int len=1;len<=13;len++){
        ll L=pw;
        ll R=min(pw*10ll-1ll,n);
        ll mx=(n+mod1-1)/mod1;
        if (R<L) break;
        res=(res-(R-L+1ll)*(mx+1ll)%mod+mod)%mod;
        for (int i=-mx;i<=mx;i++){
            res=(res+bin_search(L,R,mod1*(1-i)-1)+mod)%mod;
        }
        pw*=10ll;

    }
    cout<<(res*mod1)%mod<<endl;

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//6 3 7 5 6
/**
7 1 2
2 15 6 3 7 5 6
3 5
1
**/