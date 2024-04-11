#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[500005];
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
        int mi = INF, mid = -1;
        int ma = -INF, mad = -1;
        for(i=0;i<N;i++) {
            if(A[i]<mi) {
                mi = A[i];
                mid = i;
            }
            if(A[i]>ma) {
                ma = A[i];
                mad = i;
            }
        }
        cout << mid+1 << ' ' << mad+1 << '\n';
    }
}