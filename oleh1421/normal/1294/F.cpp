#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
const int L=19;
int h[N];
vector<int>g[N];
int p[N];
void dfs(int v,int pr){
    h[v]=h[pr]+1;
    p[v]=pr;
    for (auto to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
    }
}
int d[N];

int32_t main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    int a=1;
    for (int i=2;i<=n;i++){
        if (h[i]>h[a]) a=i;
    }
    dfs(a,0);
    int b=1;
    for (int i=2;i<=n;i++){
        if (h[i]>h[b]) b=i;
    }
    //cout<<a<<" "<<b<<endl;
    for (int i=1;i<=n;i++) d[i]=-1;
    queue<int>q;
    int cur=b;
    int cnt=0;
    while (cur){
        d[cur]=0;
        q.push(cur);
        cur=p[cur];
        cnt++;
    }
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (auto to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
    //cout<<"OK\n";
    int ind=1;
    while (ind==a || ind==b) ind++;
    for (int i=1;i<=n;i++){
        if (i==a || i==b) continue;
        if (d[i]>d[ind]) ind=i;
    }
    cout<<cnt+d[ind]-1<<endl;
    cout<<a<<" "<<b<<" "<<ind;
    return 0;
}
//0 0 1