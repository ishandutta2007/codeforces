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
        int N;
        cin >> N;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        bool isCut = true;
        int ans = 0;
        for(i=0;i<N;i++) {
            if(isCut && A[i]) {
                isCut = false;
                ans++;
            }
            else if(A[i]==0) isCut = true;
        }
        cout << min(2LL, ans) << '\n';
    }
}