#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, x, nul, one;
    nul=1;
    one=0;
    cin >> n;

    int edge[n-1][2];
    vector<int> vert[n];
    for(int i=0; i<n-1; i++){
        cin >> edge[i][0] >> edge[i][1];
        vert[edge[i][0]-1].push_back(edge[i][1]-1);
        vert[edge[i][1]-1].push_back(edge[i][0]-1);
    }

    bool color[n];
    color[0]=0;
    bool dfs_used[n];
    fill(dfs_used, dfs_used + n, 0);
    dfs_used[0]=1;
    vector<int> dfs;
    dfs.push_back(0);

    while(dfs.size()){
        x=dfs[dfs.size()-1];
        dfs.pop_back();
        for(int i=0; i<vert[x].size(); i++){
            if(dfs_used[vert[x][i]]==0){
                dfs_used[vert[x][i]]=1;
                dfs.push_back(vert[x][i]);
                color[vert[x][i]]=color[x] ^ 1;
                if(color[x]==0) one++;
                else nul++;
            }
        }
    }

    cout << nul*one-n+1;

}