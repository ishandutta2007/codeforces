#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
int B[200005];
int dis[200005];
int len[200005];
vector<vector<int> > adj;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        fill(dis, dis + N, 0);
        fill(len, len + N, 0);
        int i;
        for(i=0;i<N;i++) {
            cin >> A[i];
            A[i]--;
        }
        for(i=0;i<N;i++) {
            cin >> B[i];
            B[i]--;
        }
        adj.clear();
        adj.resize(N);
        int root;
        for(i=0;i<N;i++) {
            if(A[i] == i) root = i;
            else adj[A[i]].push_back(i);
        }
        set<int> S;
        bool isPos = true;
        S.insert(root);
        for(i=0;i<N;i++) {
            if(S.find(B[i]) == S.end()) {
                isPos = false;
                break;
            }
            S.erase(B[i]);
            dis[B[i]] = i;
            if(i > 0) len[B[i]] = dis[B[i]] - dis[A[B[i]]];
            for(int n : adj[B[i]]) {
                S.insert(n);
            }
        }
        if(isPos) {
            for(i=0;i<N;i++) cout << len[i] << ' ';
            cout << '\n';
        }
        else cout << "-1\n";
    }
}