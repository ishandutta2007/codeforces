#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[100005];
int B[100005];
int DP[100005];
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
        A[0] = 0;
        for(i=1;i<=N;i++) cin >> A[i];
        B[0] = 0;
        for(i=1;i<=N;i++) B[i] = B[i-1] + A[i];
        for(i=0;i<=N;i++) DP[i] = INF;
        DP[0] = 0;
        int xo = 0;
        map<int,int> M;
        M[xo] = 0;
        for(i=1;i<=N;i++) {
            DP[i] = min(DP[i], DP[i-1] + 1);
            xo ^= A[i];
            int pos = -1;
            if(M.count(xo)) pos = M[xo];
            if(pos != -1) {
                if(B[i] - B[pos] == 0) DP[i] = min(DP[i],DP[pos]);
                else DP[i] = min(DP[i],DP[pos] + i - pos - 1);
            }
            M[xo] = i;
        }
        cout << DP[N] << '\n';
    }
}