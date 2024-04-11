#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
using namespace std;
const int N=310000;
const int L=20;
struct BIT{
    vector<ll>t;
    void init(int n){
        t.resize(n+1,0);
    }
    void upd(int pos,ll x){
        for(;pos<t.size();pos|=pos+1) t[pos]+=x;
    }
    ll get(int pos){
        ll sum=0ll;
        for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
        return sum;
    }
};
int a[N];
int nxt[N];
int TOT=1;
vector<int>g[N];
BIT S[N];
ll cnt[N];
int pr[N];
ll val[N];
int ind[N];
int tout[N];
int up[N];
void rec(int v,int l,int r){
    ind[l-1]=v;
    ind[r+1]=v;

//    cout<<"OK "<<v<<" "<<l-1<<" "<<r+1<<endl;

    for (int i=l;i<=r;i=up[i]){
//        cout<<i<<" "<<up[i]<<endl;
        while (!up[i] && i<=r) i++;
        if (i>r) break;
        TOT++;
        g[v].push_back(TOT);
        pr[TOT]=v;
        rec(TOT,i+1,up[i]-2);
    }
    cnt[v]=g[v].size();
    S[v].init(cnt[v]);
    for (int i=0;i<cnt[v];i++) S[v].upd(i,1);
    val[v]=1+((ll)g[v].size()-1ll)*(ll)g[v].size()/2ll;
    tout[v]=TOT;
}


void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='(')-(c==')');
    }
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (a[i]==-1){
            if (!v.empty()) {
                up[v.back()]=i+1;
                v.pop_back();
            }
        } else v.push_back(i);
    }
    rec(1,1,n);
    BIT LL;
    LL.init(TOT);
    for (int i=1;i<=TOT;i++){
//        cout<<i<<" "<<val[i]<<endl;
        LL.upd(i,val[i]);
    }
    for (int i=1;i<=q;i++){
        int type;cin>>type;
        if (type==1){
            int l,r;cin>>l>>r;
            int v=ind[l];
            LL.upd(v,-1);
            LL.upd(pr[v],1-cnt[pr[v]]);
            cnt[pr[v]]--;
            int it=lower_bound(g[pr[v]].begin(),g[pr[v]].end(),v)-g[pr[v]].begin();
            S[pr[v]].upd(it,-1);
        } else {
            int l,r;cin>>l>>r;
            int L=ind[l];
            int R=ind[r];
            int P=pr[L];
//            cout<<L<<" "<<R<<" "<<P<<endl;
            int itL=lower_bound(g[P].begin(),g[P].end(),L)-g[P].begin();
            int itR=lower_bound(g[P].begin(),g[P].end(),R)-g[P].begin();
            ll cn=S[P].get(itR)-S[P].get(itL-1);
            ll res=LL.get(tout[R])-LL.get(L-1);
            res+=cn*(cn-1ll)/2ll;
            cout<<res<<endl;
        }
    }



}
int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;

}

/**

2 1073741823
1073741823 0
**/