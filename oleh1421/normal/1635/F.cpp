#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
const ll inf=4e18;
const int L=20;
int x[N];
int w[N];
ll t[N*4];
void upd(int pos,ll x){
    for (;pos<N;pos|=pos+1) t[pos]=min(t[pos],x);
}
ll get(int pos){
    ll mx=inf;
    for (;pos>=0;pos&=pos+1,pos--) mx=min(mx,t[pos]);
    return mx;
}
vector<int>Q[N];
vector<pair<int,ll> >add[N];
int l[N],r[N];
ll ans[N];
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>x[i]>>w[i];
    vector<int>suf;
    vector<pair<int,int> >best;
    for (int i=1;i<=n;i++){
        while (!suf.empty() && w[suf.back()]>=w[i]){
            best.push_back({suf.back(),i});
            suf.pop_back();
        }
        if (!suf.empty()) best.push_back({suf.back(),i});
        suf.push_back(i);
    }
    for (auto cur:best){
        int l=cur.first;
        int r=cur.second;
        ll val=(w[l]+w[r]+0ll)*(x[r]-x[l]+0ll);
        add[l].push_back({r,val});
    }
    for (int i=0;i<=n;i++) t[i]=inf;
    for (int i=1;i<=q;i++){
        cin>>l[i]>>r[i];
        Q[l[i]].push_back(i);
    }

    for (int l=n;l>=1;l--){
        for (auto cur:add[l]){
            int r=cur.first;
            ll val=cur.second;
//            cout<<l<<" "<<r<<" "<<val<<endl;
            upd(r,val);
        }
        for (int j:Q[l]){
            ans[j]=get(r[j]);
        }
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<endl;



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
/**
12837720
**/