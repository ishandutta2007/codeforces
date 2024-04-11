#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
vector<pair<int,int> >g[N];
map<pair<ll,ll>,int>mp;
int num(pair<pair<int,int>,pair<int,int> >x){
    pair<ll,ll>X={x.first.first*1ll*x.second.second*1ll,x.first.second*1ll*x.second.first*1ll};
    ll g=__gcd(X.first,X.second);
    X.first/=g;
    X.second/=g;
    if (mp.find(X)==mp.end()){
        mp[X]=mp.size();
    }
    return mp[X];
}
bool used[N];
vector<pair<int,int> >ans;
int tin[N];
int timer=0;
bool dfs(int v,int pr){
    used[v]=true;
    tin[v]=++timer;
    vector<int>E;
    for (auto cur:g[v]){
        int to=cur.first;
        int ind=cur.second;
        if (!used[to]){
            if (!dfs(to,ind)) E.push_back(ind);
        } else if (tin[to]<tin[v] && ind!=pr){
            E.push_back(ind);
        }
    }
    if (pr) E.push_back(pr);
    for (int i=1;i<E.size();i+=2){
        ans.push_back({E[i-1],E[i]});
    }
    if (E.size()%2) return false;
    else return true;
}
void solve(){
    mp.clear();
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        int u=num({{a+b,b},{c,d}});
        int v=num({{a,b},{c+d,d}});

        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    for (int i=1;i<=mp.size();i++){
        if (!used[i]){
            dfs(i,0);
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}