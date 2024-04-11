#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
int ans[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, Q;
        cin >> N >> Q;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<N;i++) ans[i] = 0;
        map<int,int> M;
        for(i=0;i<N;i++) M[A[i]]++;
        int cnt = 0;
        for(i=N-1;i>=0;i--) {
            if(cnt>=A[i]) ans[i] = 1;
            else {
                if(Q>cnt) {
                    ans[i] = 1;
                    cnt++;
                }
                else ans[i] = 0;
            }
        }
        for(i=0;i<N;i++) cout << ans[i];
        cout << '\n';
    }
}