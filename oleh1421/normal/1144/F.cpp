/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>g[300001];
int used[300001];
void dfs(int v){
    for (auto to:g[v]){
        if (used[v]==used[to]){
            cout<<"NO";
            exit(0);
        } else if (!used[to]){
            used[to]=used[v]%2+1;
            dfs(to);
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;
    vector<pair<int,int> >q;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        q.push_back({a,b});
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            used[i]=1;
            dfs(i);
        }
    }
    cout<<"YES"<<endl;
    for (auto p:q){
        cout<<used[p.first]%2;
    }
    return 0;
}