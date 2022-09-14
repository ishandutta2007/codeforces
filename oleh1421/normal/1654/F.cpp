//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=(1<<20);
const ll mod=998244353;
const ll mod1=998787811;
//const int L=20;
const ll inv2=(mod+1)/2;
vector<int>rec(int depth){
    if (!depth) return {};
    vector<int>v=rec(depth-1);
    vector<int>ans=v;
    ans.push_back(depth);
    for (int i:v) ans.push_back(i);
    return ans;
}
string s;
ll p[N];

struct SuperBor{
    ll t[N];
    ll t1[N];
    int L[N],R[N];
    int ind[N];
    void build(int v,int val,int depth){
        if (depth==0){
            t[v]=s[val]-'a';
            t1[v]=s[val]-'a';
            ind[v]=val;
            return;
        }
        L[v]=v+v;
        R[v]=v+v+1;
        build(v+v,val+val,depth-1);
        build(v+v+1,val+val+1,depth-1);
        t[v]=(t[L[v]]+p[(1<<(depth-1))]*t[R[v]])%mod;
        t1[v]=(t1[L[v]]+p[(1<<(depth-1))]*t1[R[v]])%mod1;
    }
    void upd(int v,int depth,int need){
        if (need==0){
            swap(L[v],R[v]);
            t[v]=(t[L[v]]+p[(1<<(depth-1))]*t[R[v]])%mod;
            t1[v]=(t1[L[v]]+p[(1<<(depth-1))]*t1[R[v]])%mod1;
            return;
        }
        upd(v+v,depth-1,need-1);
        upd(v+v+1,depth-1,need-1);
        t[v]=(t[L[v]]+p[(1<<(depth-1))]*t[R[v]])%mod;
        t1[v]=(t1[L[v]]+p[(1<<(depth-1))]*t1[R[v]])%mod1;

    }
};
SuperBor BEST,CUR;
bool cmp(int v,int u,int depth){
    if (depth==0) return (s[CUR.ind[v]]<s[BEST.ind[u]]);
    if (CUR.t[CUR.L[v]]==BEST.t[BEST.L[u]] && CUR.t1[CUR.L[v]]==BEST.t1[BEST.L[u]]){
        return cmp(CUR.R[v],BEST.R[u],depth-1);
    } else {
        return cmp(CUR.L[v],BEST.L[u],depth-1);
    }
}
void solve(){
    int n;cin>>n;
    cin>>s;
    vector<int>v=rec(n);
    for (auto &i:v) i--;
//    for (int i=1;i<v.size();i++) v[i]^=v[i-1];
    int last=-1;
    int xr=0;
    BEST.build(1,0,n);
    CUR.build(1,0,n);
    for (int i=0;i<v.size();i++){
        CUR.upd(1,n,v[i]);
        if (cmp(1,1,n)){

            while (last<i){
                last++;
                BEST.upd(1,n,v[last]);
                xr^=(1<<(n-v[last]-1));
            }
        }
    }
//    cout<<xr<<endl;


    for (int i=0;i<(1<<n);i++) cout<<s[i^xr];
    cout<<endl;
}
int32_t main()
{
    p[1]=29ll;
    for (int i=2;i<N;i++){
        p[i]=(p[i-1]*p[1])%mod;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

//2
//
//1 2

/**
abdbdccacbdbdccb
abdbdccacbdbdccb

**/