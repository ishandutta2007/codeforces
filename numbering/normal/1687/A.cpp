#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
int B[200005];
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
        for(i=0;i<N;i++) cin >> A[i];
        B[0] = 0;
        for(i=1;i<=N;i++) B[i] = B[i-1] + A[i-1];
        if(k <= N) {
            int ma = 0;
            for(i=k;i<=N;i++) ma = max(ma, B[i]-B[i-k]);
            ma += k*(k-1)/2;
            cout << ma << '\n';
            continue;
        }
        if(N==1) {
            cout << A[0] + k - 1 << '\n';
            continue;
        }
        int sum = B[N];
        int loop = (k)/(N-1);
        int les = k%(N-1);
        sum += loop * N*(N-1);
        sum += les*(les-1)/2;
        sum -= (N - les)*(N-les+1)/2;
        cout << sum << '\n';

    }
}