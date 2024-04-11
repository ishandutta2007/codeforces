#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
int B[500005];
int C[500005];
int D[500005];
int ans[500005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<N;i++) A[i]--;
        for(i=0;i<N;i++) C[i] = 0;
        for(i=0;i<N;i++) C[A[i]]++;
        for(i=0;i<N;i++) B[i] = i;
        sort(B, B+N, [](int x, int y){
             return C[x] > C[y];
             });
        vector<vector<int>> adj;
        adj.resize(N);
        for(i=0;i<N;i++) D[B[i]] = i;
        //cout << '\n';
        for(i=0;i<N;i++) adj[D[A[i]]].push_back(i);
        for(i=0;i<N;i++) ans[i] = -1;
        for(i=0;i<N;i++) {
            vector<int> V;
            for(int j = 0; j < N; j++) {
                if(adj[j].size()==0) break;
                V.push_back(adj[j][adj[j].size()-1]);
                adj[j].pop_back();
            }
            if(V.size()==0) break;
            int sz = V.size();
            //for(j=0;j<sz;j++) cout << V[j] <<' ';
            //cout << '\n';
            for(j=0;j<sz;j++) {
                ans[V[j]] = A[V[(j+1)%sz]];
            }
        }
        for(i=0;i<N;i++) cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
}