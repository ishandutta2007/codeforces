#include <bits/stdc++.h>
 
typedef long long ll;
//#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
const ll mod=1000000007;
int x[N];
vector<vector<int> >a;
vector<vector<int> >num;
vector<vector<int> >d;
vector<int>g[N];
vector<int>rg[N];
vector<int>order;
bool used[N];
void dfs(int v){
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]){
            dfs(to);
        }
    }
    order.push_back(v);
}
int comp[N];
int timer=0;
void dfs1(int v){
    comp[v]=timer;
    used[v]=true;
    for (int to:rg[v]){
        if (!used[to]) dfs1(to);
    }
}
int D[N];
void solve(){
    int n,m;cin>>n>>m;
 
    a.resize(n+2);
    for (int j=0;j<=n+1;j++){
        a[j].resize(m+2,0);
    }
    num=d=a;
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='#');
            if (a[i][j]){
                num[i][j]=++cnt;
            }
        }
    }
    for (int i=1;i<=m;i++) cin>>x[i];
 
    for (int i=1;i<=m;i++){
        d[n+1][i]=n+1;
        for (int j=n;j>=1;j--){
            if (a[j][i]) d[j][i]=j;
            else d[j][i]=d[j+1][i];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (!a[i][j]) continue;
            if (d[i+1][j]<=n) g[num[i][j]].push_back(num[d[i+1][j]][j]);
            if (j-1>=1 && d[i][j-1]<=n) g[num[i][j]].push_back(num[d[i][j-1]][j-1]);
            if (j+1<=m && d[i][j+1]<=n) g[num[i][j]].push_back(num[d[i][j+1]][j+1]);
            if (i>1 && a[i-1][j]) g[num[i][j]].push_back(num[i-1][j]);
        }
    }
    for (int i=1;i<=cnt;i++){
        for (int to:g[i]){
            rg[to].push_back(i);
        }
    }
    for (int i=1;i<=cnt;i++){
        if (!used[i]){
            dfs(i);
        }
    }
    for (int i=1;i<=cnt;i++) used[i]=false;
    reverse(order.begin(),order.end());
    for (int i:order){
        if (!used[i]){
            timer++;
            dfs1(i);
        }
    }
    for (int i=1;i<=cnt;i++){
        for (int to:g[i]){
            if (comp[i]!=comp[to]) D[comp[to]]++;
        }
    }
    int res=0;
    for (int i=1;i<=timer;i++){
        if (D[i]==0) res++;
    }
    res=max(res,(int)(cnt>0));
    cout<<res<<endl;
 
}
int32_t main() {
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