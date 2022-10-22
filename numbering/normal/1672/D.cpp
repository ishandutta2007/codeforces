#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
int B[500005];
int C[500005];
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
        for(i=0;i<N;i++) cin >> B[i];
        for(i=0;i<N;i++) C[i] = 0;
        for(i=0;i<N;i++) {
            A[i]--;
            B[i]--;
        }
        bool isPos = true;
        int j = N-1;
        for(i=N-1;i>=0;i--) {
            if(j<0||A[i]!=B[j]) {
                if(C[A[i]]) C[A[i]]--;
                else isPos = false;
            }
            else {
                C[A[i]]--;
                while(j>=0&&A[i]==B[j]) {
                    C[A[i]]++;
                    j--;
                }
            }
        }
        cout << (isPos ? "YES\n" : "NO\n");
    }
}