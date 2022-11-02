#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, ans;
    ans=0;
    cin >> n;
    int col;

    vector<int> dfs;
    int dfs_used[n];
    fill(dfs_used, dfs_used + n, 0);
    dfs_used[0]=1;
    dfs.push_back(0);
    vector<int> sons[n];
    int par[n];
    for(int i=1; i<n; i++){
        cin >> par[i];
        par[i]--;
        sons[par[i]].push_back(i-1);
    }

    int c[n];
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    col=c[0];

    for(int i=1; i<n; i++){
        if(c[i]!=c[par[i]]) ans++;
    }

    cout << ans+1;


}