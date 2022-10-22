#include <bits/stdc++.h>
using namespace std;
bool A[1000005];
int ans[1000005];
int B[1000005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        string s;
        cin >> s;
        int i, j;
        for(i=1;i<=s.length();i++) ans[i] = 0;
        for(i=0;i<M;i++) A[i] = true;
        int cnt = 0;
        for(i=1;i<=s.length();i++) {
            if(s[i-1]=='1') {
                if(A[i%M]) {
                    A[i%M]=false;
                    cnt++;
                }
            }
            ans[i] += cnt;
        }
        //for(i=1;i<=N*M;i++) cout << ans[i] << ' ';
        //cout << '\n';
        B[0] = 0;
        for(i=1;i<=s.length();i++) {
            if(s[i-1]=='1') B[i] = B[i-1] + 1;
            else B[i] = B[i-1];
        }
        for(i=1;i<=M;i++) {
            int ck = (B[i] > 0 ? 1 : 0);
            ans[i] += ck;
            for(j=i+M;j<=N*M;j+=M) {
                if(B[j]-B[j-M] > 0) ck++;
                ans[j] += ck;
            }
        }
        for(i=1;i<=N*M;i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}