#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
vector<vector<int> > adj;
vector<int> deg;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, k;
        cin >> N >> k;
        adj.clear();
        deg.clear();
        adj.resize(N);
        deg.resize(N);
        int a, b;
        int i;
        for(i=0;i<N-1;i++) {
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        deque<int> Q;
        vector<int> lev;
        lev.resize(N);
        for(i=0;i<N;i++) {
            if(deg[i] == 1) {
                Q.push_back(i);
                lev[i] = 1;
                //cout << i << ' ';
            }
        }
        //cout << '\n';
        while(!Q.empty()) {
            int c = Q.front();
            //cout << c+1 << ' ' << lev[c] << '\n';
            Q.pop_front();
            for(int n : adj[c]) {
                deg[n]--;
                if(deg[n] == 1) {
                    lev[n] = lev[c] + 1;
                    Q.push_back(n);
                }
            }
        }
        int ans = 0;
        for(i=0;i<N;i++) {
            if(lev[i] > k) ans++;
        }
        cout << ans << '\n';
    }
}