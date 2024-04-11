#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[100005];
int B[100005];
typedef pair<int,int> P;
int D1[20005];
int D2[20005];
int D[20005];
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
        int ans = 0;
        for(i=0;i<N;i++) {
            ans += (N-2)*(A[i]*A[i]+B[i]*B[i]);
        }
        for(i=0;i<=20000;i++) D[i] = 0;
        D[0] = 1;
        for(int j = 0; j < N ;j++) {
            for(i=0;i<=20000;i++) D1[i] = D2[i] = 0;
            for(i=0;i<=20000;i++) {
                if(D[i]!=0) {
                    if(i+A[j]<=20000)D1[i+A[j]] = 1;
                    if(i+B[j]<=20000)D2[i+B[j]] = 1;
                }
            }
            for(i=0;i<=20000;i++) {
                if(D1[i]==1||D2[i]==1) D[i] = 1;
                else D[i] = 0;
            }
        }
        int sum = 0;
        for(i=0;i<N;i++) sum += A[i] + B[i];
        int mi = INF;
        for(i=0;i<=20000;i++) {
            if(D[i]) {
                mi = min(mi, i*i+(sum-i)*(sum-i));
            }
        }
        ans += mi;
        cout << ans << '\n';
    }
}