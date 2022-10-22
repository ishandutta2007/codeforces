#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i;
        int N, x;
        cin >> N >> x;
        for(i=0;i<N;i++) cin >> A[i];
        int cnt = 0;
        int mi = INF, ma = -INF;
        for(i=0;i<N;i++) {
            mi = min(mi, A[i]);
            ma = max(ma, A[i]);
            if(ma - mi > 2*x) {
                cnt++;
                mi = A[i];
                ma = A[i];
            }
        }
        cout << cnt << '\n';
    }
}