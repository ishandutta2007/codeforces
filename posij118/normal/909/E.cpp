#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, x, ans;
    ans=0;
    cin >> N >> M;

    vector<int> graph[N];
    int indeg[N];
    fill(indeg, indeg + N, 0);
    bool cop[N];

    for(int i=0; i<N; i++){
        cin >> cop[i];
    }

    int edges[M][2];
    for(int i=0; i<M; i++){
        cin >> edges[i][0] >> edges[i][1];
        graph[edges[i][1]].push_back(edges[i][0]);
        indeg[edges[i][0]]++;
    }

    vector<int> dfs;
    vector<int> dfs_cop;
    int dfs_used[N];
    fill(dfs_used, dfs_used + N, 0);

    for(int i=0; i<N; i++){
        if(indeg[i]==0){
            if(cop[i]==0) dfs.push_back(i);
            else dfs_cop.push_back(i);

            dfs_used[i]=1;
        }
    }

    while(dfs.size() || dfs_cop.size()){
        while(dfs.size()){
            x=dfs[dfs.size()-1];
            dfs.pop_back();
            for(int i=0; i<graph[x].size(); i++){
                if(dfs_used[graph[x][i]]==0){
                    indeg[graph[x][i]]--;
                    if(indeg[graph[x][i]]==0){
                        dfs_used[graph[x][i]]=1;
                        if(cop[graph[x][i]]==0) dfs.push_back(graph[x][i]);
                        else dfs_cop.push_back(graph[x][i]);
                    }
                }
            }
        }
        if(dfs_cop.size()) ans++;
        while(dfs_cop.size()){

            x=dfs_cop[dfs_cop.size()-1];
            dfs_cop.pop_back();
            for(int i=0; i<graph[x].size(); i++){
                if(dfs_used[graph[x][i]]==0){
                    indeg[graph[x][i]]--;
                    if(indeg[graph[x][i]]==0){
                        dfs_used[graph[x][i]]=1;
                        if(cop[graph[x][i]]==0) dfs.push_back(graph[x][i]);
                        else dfs_cop.push_back(graph[x][i]);
                    }
                }
            }
        }

    }

    cout << ans;
}