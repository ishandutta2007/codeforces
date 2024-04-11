#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
int B[500005];
int C[500005];
int D[500005];
int E[500005];
int F[500005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        int K;
        cin >> K;
        for(i=0;i<K;i++) cin >> B[i];
        for(i=0;i<max(N,K);i++) C[i] = D[i] = 0;
        for(i=0;i<max(N,K);i++) E[i] = F[i] = 0;
        int p1 = 0, p2 = 0;
        for(i=0;i<N;i++) {
            int cnt = 1;
            while(A[i]%M==0) {
                A[i] /= M;
                cnt *= M;
            }
            if(i&&A[i-1]==A[i]) {
                C[p1-1] += cnt;
            }
            else {
                C[p1] = cnt;
                D[p1] = A[i];
                p1++;
            }
        }
        for(i=0;i<K;i++) {
            int cnt = 1;
            while(B[i]%M==0) {
                B[i] /= M;
                cnt *= M;
            }
            if(i&&B[i-1]==B[i]) {
                E[p2-1] += cnt;
            }
            else {
                E[p2] = cnt;
                F[p2] = B[i];
                p2++;
            }
        }
        bool isPos = true;
        if(p1!=p2) isPos = false;
        for(i=0;i<max(p1,p2);i++) {
            if(C[i]!=E[i]||D[i]!=F[i]) isPos = false;
        }
        /*for(i=0;i<p1;i++) cout << C[i] << " : " << D[i] << '\n';
        for(i=0;i<p2;i++) cout << E[i] << " : " << F[i] << '\n';*/
        cout << (isPos ? "Yes\n" : "No\n");
    }
}