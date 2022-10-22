#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[1000005];
int B[1000005];
int C[1000005];
bool pos[1000005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, c;
        cin >> N >> c;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<=c;i++) B[i] = 0;
        for(i=0;i<N;i++) B[A[i]]++;
        for(i=0;i<=c;i++) C[i] = 0;
        for(i=1;i<=c;i++) C[i] = C[i-1] + B[i];
        for(i=0;i<=c;i++) pos[i] = false;
        for(i=1;i<=c;i++) {
            if(B[i]) {
                for(j=i;j<=c;j+=i) {
                    if(C[min(c,i+j-1)]-C[j-1]>0) pos[j/i] = true;
                }
            }
        }
        bool isPos = true;
        for(i=1;i<=c;i++) {
            if(pos[i]&&!B[i]) {
                //cout << i << ' ';
                isPos = false;
            }
        }
        cout << (isPos ? "Yes\n" : "No\n");
    }
}