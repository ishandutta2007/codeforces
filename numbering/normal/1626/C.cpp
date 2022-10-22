#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int K[105];
int H[105];
int A[105];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i, j, k;
        for(i=0;i<N;i++) cin >> K[i];
        for(i=0;i<N;i++) cin >> H[i];
        for(i=0;i<N;i++) A[i] = K[i] - H[i];
        int st = 0;
        int ans = 0;
        K[N] = 2 * 1e9;
        H[N] = 0;
        while(st < N) {
            int mi = INF;
            int pos = -1;
            int pos2 = -1;
            for(i=st;i<N;i++) {
                if(mi >= A[i]) {
                    mi = A[i];
                    pos2 = i;
                }
            }
            for(i=pos2+1;i<N;i++) {
                if(K[pos2] > K[i]-H[i]) {
                    pos2 = i;
                }
            }
            ans += (K[pos2]-mi) * (K[pos2]-mi+1)/2;
            st = pos2 + 1;
        }
        cout << ans << '\n';
    }
}