#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
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
        if(N == 1) {
            cout << "1\n";
            continue;
        }
        if(A[0] != N && A[N-1] != N) {
            cout << "-1\n";
            continue;
        }
        int pt;
        for(i=0;i<N;i++) {
            if(A[i] == N-1) pt = i;
        }
        if(A[N-1] == N) {
            cout << N-1 << ' ';
            for(i=pt-1;i>=0;i--) cout << A[i] << ' ';
            cout << N << ' ';
            for(i=N-2;i>=pt+1;i--) cout << A[i] << ' ';
            cout << '\n';
        }
        else {
            for(i=pt-1;i>=1;i--) cout << A[i] << ' ';
            cout << N << ' ';
            for(i=N-1;i>=pt+1;i--) cout <<A[i] << ' ';
            cout << N-1 << '\n';
        }
    }
}