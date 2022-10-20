#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<string> a;
vector<int> adj[400400], inv[400400];
bool visited[400400];
stack<int> st;
int sccnum[400400], deg[400400], cur = 1;

void dfs1(int s){
    visited[s] = 1;
    for (auto &v:adj[s]) if (!visited[v]) dfs1(v);
    st.push(s);
}

void dfs2(int s){
    visited[s] = 1;
    sccnum[s] = cur;
    for (auto &v:inv[s]) if (!visited[v]) dfs2(v);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i=0;i<n;i++){
        a[i].resize(m);
        cin >> a[i];
    }
    for (int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
    }
    for (int j=0;j<m;j++){
        for (int i=0;i<n;i++) if (a[i][j]=='#'){
            if (i && a[i-1][j]=='#') adj[i*m+j].push_back((i-1)*m+j);
            int nxt = n;
            for (int k=i+1;k<n;k++) if (a[k][j]=='#'){
                nxt = k; break;
            }
            if (nxt<n) adj[i*m+j].push_back(nxt*m+j);
            if (j){
                for (int k=i;k<nxt;k++) if (a[k][j-1]=='#'){
                    adj[i*m+j].push_back(k*m+j-1);
                    break;
                }
            }
            if (j<m-1){
                for (int k=i;k<nxt;k++) if (a[k][j+1]=='#'){
                    adj[i*m+j].push_back(k*m+j+1);
                    break;
                }
            }
        }
    }
    for (int i=0;i<n*m;i++){
        for (auto &j:adj[i]){
            inv[j].push_back(i);
        }
    }

    for (int i=0;i<n*m;i++) if (a[i/m][i%m]=='#' && !visited[i]) dfs1(i);
    fill(visited, visited+n*m, 0);
    while(!st.empty()){
        int s = st.top(); st.pop();
        if (visited[s]) continue;
        dfs2(s);
        cur++;
    }

    for (int i=0;i<n*m;i++){
        for (auto &j:adj[i]) if (sccnum[i]!=sccnum[j]) deg[sccnum[j]]++;
    }
    int ans = 0;
    for (int i=1;i<cur;i++) if (!deg[i]) ans++;
    printf("%d\n", ans);
    return 0;
}