#include <bits/stdc++.h>
#define int long long
const int INF = 1e18;
using namespace std;
int A[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, k;
        cin >> N >> k;
        int i, j;
        int mi = INF;
        int sum2 = 0;
        for(i=0;i<N;i++) {
            cin >> A[i];
            sum2 += A[i];
            mi = min(A[i], mi);
        }
        if(sum2 <= k) {
            cout << "0\n";
            continue;
        }
        sort(A, A+N);
        int ans = INF;
        for(i=0;i<N;i++) {
            int cnt;
            if(k >= 0) cnt = k / (N - i);
            else cnt = (-k)%(N-i)==0 ? -(-k)/(N-i) : -(-k)/(N-i)-1;
            ans = min(ans, max(mi - cnt,0LL) + N - i - 1);
            //cout << i << " : "<< max(mi - cnt,0LL) + N - i - 1 << '\n';
            k -= A[i+1];
            //cout << k << '\n';
            //if(k < 0) break;
        }
        cout << ans << '\n';
    }
}