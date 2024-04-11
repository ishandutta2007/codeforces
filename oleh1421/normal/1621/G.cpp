#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=201050;
const ll mod=1000000007;
int n,k;
int a[N];
ll t[N];
ll get(int pos){
    ll sum=0ll;
    for (;pos>=0;pos&=pos+1,pos--) sum=(sum+t[pos])%mod;
    return sum;
}
void upd(int n,int pos,ll x){
    for (;pos<=n;pos|=pos+1) t[pos]=(t[pos]+x)%mod;
}
ll cnt[3][N];
void calc(int type,vector<int>v){
    for (int i:v){
        cnt[type][i]=(get(a[i]-1)+1)%mod;
        upd(k,a[i],cnt[type][i]);
    }
    for (int i:v){
        upd(k,a[i],mod-cnt[type][i]);
    }
}
vector<int>g[N];
int gr[N];
void solve(){
    cin>>n;
    set<int>st;
    map<int,int>mp;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        st.insert(a[i]);
    }
    k=0;
    for (int x:st){
        mp[x]=++k;
    }
    for (int i=1;i<=n;i++) a[i]=mp[a[i]];
    vector<int>all;
    for (int i=1;i<=n;i++){
        all.push_back(i);
    }
    calc(0,all);
    for (int i=1;i<=n;i++) a[i]=k-a[i]+1;
    reverse(all.begin(),all.end());
    calc(2,all);
    vector<pair<int,int> >suf;
    for (int i=n;i>=1;i--){
        if (suf.empty() || a[i]<suf.back().first) suf.push_back({a[i],i});
    }
    suf.push_back({0,0});
    reverse(suf.begin(),suf.end());
    for (int i=1;i<=n;i++){
        pair<int,int>fnd={a[i],0};
        auto it=lower_bound(suf.begin(),suf.end(),fnd);
        if (it==suf.begin()) gr[i]=0;
        else {
            it--;
            if ((*it).second<=i) gr[i]=0;
            else gr[i]=(*it).second;
        }
    }
    for (int i=n;i>=1;i--){
        if (gr[i]) g[gr[i]].push_back(i);
    }
    for (int i=1;i<=n;i++){
        calc(1,g[i]);
    }

    ll res=0ll;
    for (int i=1;i<=n;i++){
        if (gr[i]) {
//            cout<<i<<" "<<gr[i]<<" "<<cnt[0][i]<<" "<<cnt[1][i]<<" "<<cnt[2][i]<<endl;
            res+=cnt[0][i]*(mod+cnt[2][i]-cnt[1][i]);
            res%=mod;
        }
    }
    cout<<res<<endl;

    for (int i=0;i<=n;i++){
        cnt[0][i]=cnt[1][i]=cnt[2][i]=0;
        g[i].clear();
    }



}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}