#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i;
        for(i=0;i<N;i++) cin >> A[i];
        int ans = 0;
        for(i=0;i<N;i++) {
            int c = 1 + (A[i]==0?1:0);
            ans += c * (i+1) * (N-i);
        }
        cout << ans << '\n';
    }
}