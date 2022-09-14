#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
const int N=500010;
pair<int,int>A[N];
pair<int,int>B[N];
vector<pair<int,int> >g[N];
vector<char>ans[N];
bool used[N];
void dfs(int v){

    while (!g[v].empty()){
        int ind=g[v].back().second;
        int to=g[v].back().first;
        g[v].pop_back();
        if (used[ind]) continue;
        used[ind]=true;
        if (A[ind].first==v){
            ans[A[ind].first][A[ind].second]='L';
            ans[B[ind].first][B[ind].second]='R';
        } else {
            ans[A[ind].first][A[ind].second]='R';
            ans[B[ind].first][B[ind].second]='L';
        }
        dfs(to);
    }

}
void solve(){
    int n;cin>>n;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        int m;cin>>m;
        ans[i].resize(m);
        for (int j=0;j<m;j++){
            int x;cin>>x;
            v.push_back({x,{i,j}});
        }
    }
    sort(v.begin(),v.end());
    int E=0;
    for (int i=0;i<v.size();i+=2){
        if (v[i].first!=v[i+1].first){
            cout<<"NO\n";
            return;
        }
        E++;
        A[E]=v[i].second;
        B[E]=v[i+1].second;
    }
    for (int i=1;i<=E;i++){
        g[A[i].first].push_back({B[i].first,i});
        g[B[i].first].push_back({A[i].first,i});
    }

    for (int i=1;i<=n;i++){
        dfs(i);
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++){
        for (auto j:ans[i]) cout<<j;
        cout<<endl;
    }




}
int32_t  main()
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

**/