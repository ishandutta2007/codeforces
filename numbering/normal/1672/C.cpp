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
        int i;
        for(i=0;i<N;i++) cin >> A[i];
        int ans = -1;
        int m1 = N+1, m2 = -1;
        for(i=0;i+1<N;i++) {
            if(A[i]==A[i+1]) {
                m1 = min(m1, i);
                m2 = max(m2, i);
            }
        }
        if(m2==-1||m1==m2) cout << "0\n";
        else cout << max(m2-m1-1,1LL) << '\n';
    }
}