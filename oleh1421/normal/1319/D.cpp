#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=200010;
int d[N];
int dp[N];
vector<int>g[N];
vector<int>r[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        r[y].push_back(x);
    }
    vector<int>p;
    int k;cin>>k;
    for (int i=1;i<=k;i++){
        int x;cin>>x;
        p.push_back(x);
    }
    int s=p[0];
    int t=p.back();
    for (int i=1;i<=n;i++) d[i]=-1,dp[i]=0;
    d[t]=0;
    dp[t]=1;
    queue<int>q;
    q.push(t);
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (auto to:r[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                dp[to]=1;
                q.push(to);
            } else if (d[to]==d[v]+1){
                dp[to]=2;
            }
        }
    }
    int minx=0;
    int maxx=0;
    for(int i=1;i<p.size();i++){
        if (d[p[i-1]]!=d[p[i]]+1){
            minx++;
            maxx++;
        } else if (dp[p[i-1]]==2) maxx++;
    }
    cout<<minx<<" "<<maxx;
    return 0;
}