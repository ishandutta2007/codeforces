#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
int p[N];
int pos[N];
int q[N];
void solve(){
    ll x;cin>>x;
    vector<pair<ll,vector<ll> > >basis;
    for (ll i=1;i<=10000000;i++){
        ll y=(x*i);
        for (auto &cur:basis){
            ll z=cur.first;
            ll nxt=(y^z);
            if (nxt<y){
                y=nxt;
            }
        }
        if (y) {
            y=x*i;
            set<ll>st={i};
            for (auto cur:basis){
                ll z=cur.first;
                ll nxt=(y^z);
                if (nxt<y){
                    y=nxt;
                    for (ll j:cur.second){
                        if (st.find(j)==st.end()) st.insert(j);
                        else st.erase(j);
                    }
                }
            }
            vector<ll>v;
            for (ll j:st) v.push_back(j);
            basis.push_back({y,v});
        }
 
        if (y==1){
            break;
        }
    }
    vector<ll>v=basis.back().second;
//    for (ll i:v) cout<<i<<endl;
    vector<pair<int,pair<ll,ll> > >ans;
    for (ll i=0;i<30;i++){
        ans.push_back({1,{x*(1ll<<i),x*(1ll<<i)}});
    }
    for (ll y:v){
        ll cur=0ll;
        for (ll i=0;i<30;i++){
            if (y&(1ll<<i)){
                if (cur) ans.push_back({1,{cur,x*(1ll<<i)}});
                cur+=x*(1ll<<i);
            }
        }
    }
    ll cur=v[0]*x;
    for (int i=1;i<v.size();i++){
        ans.push_back({2,{cur,v[i]*x}});
        cur^=v[i]*x;
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans){
        if (cur.first==1) cout<<cur.second.first<<" + "<<cur.second.second<<endl;
        else cout<<cur.second.first<<" ^ "<<cur.second.second<<endl;
    }
}
///6 18 21
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}