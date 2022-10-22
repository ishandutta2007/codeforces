#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, z;
        cin >> N >> z;
        int i;
        for(i=0;i<N;i++) cin >> A[i];
        int ma = 0;
        for(i=0;i<N;i++) ma = max(ma, z|A[i]);
        cout << ma << '\n';
    }
}