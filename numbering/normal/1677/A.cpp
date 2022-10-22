#include <bits/stdc++.h>
using namespace std;
int A[5005];
int B[5005][5005];
int C[5005][5005];
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
        for(i=0;i<N;i++) A[i]--;
        for(i=0;i<N;i++) {
            B[N-1][i] = i;
            for(j=N-2;j>=0;j--) {
                if(A[j+1]<i) B[j][i] = B[j+1][i]-1;
                else B[j][i] = B[j+1][i];
            }
            C[0][i] = i;
            for(j=1;j<N;j++) {
                if(A[j-1]<i) C[j][i] = C[j-1][i]-1;
                else C[j][i] = C[j-1][i];
            }
        }
        long long int ans = 0;
        for(i=1;i<N-1;i++) {
            for(j=i+1;j<N-1;j++) {
                ans += 1LL*B[i-1][A[j]] * C[j+1][A[i]];
            }
        }
        cout << ans << '\n';
    }
}