#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[200005];
int B[200005];
int D[200005];
typedef pair<int,int> P;
vector<vector<int>> adj;
const int p = 998244353;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N, M;
        cin >> N >> M;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<N;i++) B[i] = 0;
        adj.clear();
        adj.resize(N);
        vector<int> ord(N, 0);
        for(i=0;i<M;i++) {
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            ord[b-1]++;
        }
        queue<int> Q;
        for(i=0;i<N;i++) {
            if(ord[i]==0) Q.push(i);
        }
        int cnt = 0;
        while(!Q.empty()) {
            int c = Q.front();
            Q.pop();
            B[cnt] = c;
            cnt++;
            for(int n : adj[c]) {
                ord[n]--;
                if(ord[n]==0) Q.push(n);
            }
        }
        assert(cnt==N);
        int ans = 0;
        bool isEn = false;
        for(ans=0;ans<=2*N;ans++) {
            bool isEnd = true;
            for(j=N-1;j>=0;j--) {
                i = B[j];
                if(A[i]) {
                    isEnd = false;
                    for(int n : adj[i]) A[n]++;
                    A[i]--;
                }
            }
            if(isEnd) {
                isEn = true;
                break;
            }
        }
        for(i=0;i<N;i++) D[i] = 0;
        D[B[N-1]] = 1;
        for(i=N-2;i>=0;i--) {
            int j = B[i];
            for(int m : adj[j]) {
                D[j] += D[m];
                D[j] %= p;
            }
        }
        for(i=0;i<N;i++) {
            ans += D[i] * A[i] % p;
            ans %= p;
        }
        cout << ans << '\n';
    }
}