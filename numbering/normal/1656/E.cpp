#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
vector<vector<int>> adj;
int lev[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        adj.clear();
        int N;
        cin >> N;
        adj.resize(N);
        int i, j;
        for(i=0;i<N-1;i++) {
            int a, b;
            cin >> a >>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        for(i=0;i<N;i++) lev[i] = -1;
        queue<int> Q;
        lev[0] = 0;
        Q.push(0);
        while(!Q.empty()) {
            int c = Q.front();
            Q.pop();
            for(int n : adj[c]) {
                if(lev[n]==-1) {
                    lev[n] = lev[c] + 1;
                    Q.push(n);
                }
            }
        }
        for(i=0;i<N;i++) {
            if(lev[i]%2) {
                cout << adj[i].size() << ' ';
            }
            else {
                cout << (-1) * (int)(adj[i].size()) << ' ';
            }
        }
        cout << '\n';
    }
}