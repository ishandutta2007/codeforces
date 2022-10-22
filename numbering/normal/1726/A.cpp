#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N;
        cin >> N;
        for(i=0;i<N;i++) cin >> A[i];
        int ans = A[N-1] - A[0];
        for(i=0;i+1<N;i++) {
            ans = max(ans, A[i] - A[i+1]);
        }
        for(i=1;i<N;i++) {
            ans = max(ans, A[i] - A[0]);
        }
        for(i=0;i+1<N;i++) {
            ans = max(ans, A[N-1] - A[i]);
        }
        cout << ans << '\n';
    }
}