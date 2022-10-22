#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[200005];
int B[200005];
bool solve(int N, int k) { //All more than k
    int i, j;
    for(i=0;i<N;i++) B[i] = A[i];
    //cout << k << '\n';
    for(i=N-1;i>=2;i--) {
        if(B[i] < k) return false;
        int d = (B[i] - k) / 3;
        d = min(d, A[i]/3);
        B[i] -= 3*d;
        B[i-1] += d;
        B[i-2] += 2*d;
    }
    return B[0] >= k && B[1] >= k;
}
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
        int s = 1, e = 1e9 + 1;
        while(s+1<e) {
            //cout << s << ' ' << e << '\n';
            int mid = s + e >> 1;
            if(solve(N, mid)) s = mid;
            else e = mid;
        }
        cout << s << '\n';
    }
}