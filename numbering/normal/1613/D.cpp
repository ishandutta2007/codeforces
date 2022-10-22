#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int A[500005];
int power(int a, int b, int c) {
    a %= c;
    if(b==0) return 1;
    if(b==1) return a;
    if(a==0) return 0;
    if(a==1) return 1;
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k * k % c;
    }
    if(b % 2 == 1) {
        int k = power(a, b-1, c);
        return k * a % c;
    }
}

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int i, j, k;
    while(t--) {
        int N;
        cin >> N;
        for(i=0;i<N;i++) cin >> A[i];

        vector<vector<int> > adj;
        vector<map<int,int> > M;
        M.resize(N+5);
        adj.resize(N+5);
        for(i=0;i<N;i++) {
            if(A[i] >= 1) adj[A[i]-1].push_back(i);
            if(A[i] < N) adj[A[i]+1].push_back(i);
        }
        for(i=0;i<=N;i++) {
            int sz = adj[i].size();
            for(j=0;j<sz;j++) {
                M[i][adj[i][j]] = sz-j-1;
            }
        }
        int ans = 0;
        vector<int> C(N+5);
        C[0] = 1;
        for(i=0;i<N;i++) {

            if(A[i] >= 1) {
                //cout << M[A[i]-1][i] << '\n';
                ans += C[A[i]-1] * power(2, M[A[i]-1][i], p);
                ans %= p;
            }
            //cout << ans << ' ';
            ans += C[A[i]];
            ans %= p;
            //cout << ans << ' ';
            ans += C[A[i]+1];
            ans %= p;
            //cout << ans << ' ';
            C[A[i]+1] += C[A[i]] + C[A[i]+1];
            C[A[i]+1] %= p;
            //cout << i << ' ' << ans << '\n';
        }
        cout << ans << '\n';
    }
}