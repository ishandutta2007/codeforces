#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=1501050;
int w[N],c[N];
int mult[N];
int cnt[N];
vector<pair<int,int> >g[N];
ll TOT=0ll;
void dfs(int v,int pr,ll depth){
    cnt[v]=0;
    for (auto cur:g[v]){
        int to=cur.first;
        int ind=cur.second;
        if (to==pr) continue;
        dfs(to,v,depth+w[ind]);
        mult[ind]=cnt[to];
        cnt[v]+=cnt[to];
    }
    if (cnt[v]==0){
        TOT+=depth;
        cnt[v]=1;
    }
}
void solve(){

    int n;cin>>n;
    ll S;cin>>S;
    for (int i=1;i<n;i++){
        int u,v;cin>>u>>v>>w[i]>>c[i];
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    dfs(1,0,0);
//    vector<ll>v;
//    for (int i=1;i<n;i++){
//        while (w[i]){
//            v.push_back(mult[i]*(w[i]-w[i]/2));
//            w[i]/=2;
//        }
//    }
//    sort(v.begin(),v.end());
//    reverse(v.begin(),v.end());
//    ll ans=(int)v.size();
//    for (int i=0;i<v.size();i++){
//        if (TOT<=S){
//            ans=i;
//            break;
//        }
//        TOT-=v[i];
//    }
//    cout<<ans<<endl;
    if (TOT<=S){
        cout<<0<<endl;
    } else {
        S=TOT-S;
        vector<vector<ll> >add(2);
        for (int i=1;i<n;i++){
            while (w[i]){
                add[c[i]-1].push_back(mult[i]*(w[i]-w[i]/2));
                w[i]/=2;
            }
        }
        sort(add[0].begin(),add[0].end());
        add[0].push_back(0);
        reverse(add[0].begin(),add[0].end());
        for (int i=1;i<add[0].size();i++) add[0][i]+=add[0][i-1];
        sort(add[1].begin(),add[1].end());
        add[1].push_back(0);
        reverse(add[1].begin(),add[1].end());
        for (int i=1;i<add[1].size();i++) add[1][i]+=add[1][i-1];
//        int ans=lower_bound(add[0].begin(),add[0].end(),S)-add[0].begin();
//        for (int i=0;i<add[0].size();i++){
//            if (add[0][i]>=S){
//                ans=i;
//                break;
//            }
//        }
        ll res=1e18;
        for (int i=0;i<add[1].size();i++){
            int ind=lower_bound(add[0].begin(),add[0].end(),S-add[1][i])-add[0].begin();
            if (ind==add[0].size()) continue;
            res=min(res,i*2+ind);
        }
        cout<<res<<endl;
    }
    TOT=0ll;
    for (int i=1;i<=n;i++){
        g[i].clear();
        mult[i]=cnt[i]=w[i]=c[i]=0;
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



/**
5 50
1 3 100 1
1 5 10 2
2 3 123 2
5 4 55 1
2 100
1 2 409 2
**/