#include <bits/stdc++.h>
#define int long long
using namespace std;
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
        vector<int> A(N);
        for(i=0;i<N;i++) cin >> A[i];
        sort(A.begin(),A.end());
        for(i=1;i<=N/2;i++) cout << A[i] << ' ' << A[0] << '\n';
    }
}