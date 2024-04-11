#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100];
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
        int cnt = 0;
        int ma = 0;
        int sum = 0;
        for(i=0;i<N;i++) {
            while(A[i]%2==0) {
                cnt++;
                A[i]/=2;
            }
            ma = max(ma, A[i]);
            sum += A[i];
        }
        int k = 1;
        while(cnt) {
            k *= 2;
            cnt--;
        }
        cout << sum + (k-1)*ma << '\n';
    }
}