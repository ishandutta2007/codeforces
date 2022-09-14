//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//typedef __int128 ll;
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=2010;
int a[N][N];
int pr[N*N];
int c[N*N];
vector<pair<int,int> >vv[N*10];
vector<int>g[N];
bool used[N*N];
int dsu[N*N];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
vector<int>order;
void dfs(int v){
    used[v]=true;
    order.push_back(v);
    for (int to:g[v]){
        if (!used[to]){
            dfs(to);
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            if (i<j) vv[a[i][j]].push_back({i,j});
        }
    }
    int cur=n;
    for (int i=1;i<=n;i++) c[i]=a[i][i];
    for (int i=1;i<=n*n;i++) dsu[i]=i;
    for (int cc=1;cc<=5000;cc++){
        for (int i=1;i<=n;i++) used[get(i)]=false,g[get(i)].clear();
        for (auto cur:vv[cc]){
            int a=cur.first;
            int b=cur.second;
            a=get(a);
            b=get(b);
            g[a].push_back(b);
            g[b].push_back(a);
//            cout<<"E "<<a<<" "<<b<<" "<<cc<<endl;
        }
        for (int i=1;i<=n;i++){
            int v=get(i);

            if (!used[v] && !g[v].empty()){
                dfs(v);
                cur++;
                c[cur]=cc;

                for (int j:order){
                    pr[j]=cur;
                    dsu[j]=cur;
                }
                order.clear();
            }
        }
    }
    cout<<cur<<endl;
    for (int i=1;i<=cur;i++) cout<<c[i]<<" ";
    cout<<endl<<cur<<endl;
    for (int i=1;i<cur;i++) cout<<i<<" "<<pr[i]<<endl;
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