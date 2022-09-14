//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=200010;
int used[N];
vector<int>g[N];
vector<int>order;
int h[N];
vector<int>ans[2];
int n,m,k;
int cur=10000001;
void dfs(int v,int pr){
    used[v]=1;
    h[v]=order.size();
    ans[h[v]%2].push_back(v);
    order.push_back(v);
    for (auto to:g[v]){
        if (to!=pr){
            if (used[to]==1){
                cur=min(cur,h[v]-h[to]+1);
            } else if (!used[to]){
                dfs(to,v);
            }
        }
    }
    order.pop_back();
    used[v]=2;
}
void dfs1(int v,int pr){
    used[v]=1;
    h[v]=order.size();
    order.push_back(v);
    for (auto to:g[v]){
        if (to!=pr){
            if (used[to]==1){
                if (h[v]-h[to]+1==cur){
                    vector<int>cycle;
                    for (int i=h[to];i<=h[v];i++) cycle.push_back(order[i]);
                    if (cycle.size()<=k){
                        cout<<2<<endl;
                        cout<<cycle.size()<<endl;
                        for (auto i:cycle) cout<<i<<" ";
                        cout<<endl;
                    } else {
                        cout<<1<<endl;
                        for (int i=0;i<(k+1)/2;i++){
                            cout<<cycle[i*2]<<" ";
                        }
                        cout<<endl;
                    }
                    exit(0);
                }
            } else if (!used[to]){
                dfs1(to,v);
            }
        }
    }
    order.pop_back();
    used[v]=2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    if (cur==10000001){
        if (ans[0].size()<ans[1].size()) swap(ans[0],ans[1]);
        cout<<1<<endl;
        for (int i=0;i<(k+1)/2;i++){
            cout<<ans[0][i]<<" ";
        }
        cout<<endl;
        return 0;
    }
//    cout<<cur<<endl;
    for (int i=1;i<=n;i++) used[i]=0;
    dfs1(1,0);
    return 0;
}
/*
4 6 3
1 2
2 3
3 4
4 1
1 3
2 4
*/