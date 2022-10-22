#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[5005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int i, j;
    for(i=0;i<N;i++) cin >> A[i];
    int ans = INF;
    for(i=0;i<N;i++) {
        int cnt = 0;
        int a = 0;
        for(j=i+1;j<N;j++) {
            cnt += (a / A[j]) + 1;
            a = ((a/A[j])+1)*A[j];
        }
        a = 0;
        for(j=i-1;j>=0;j--) {
            cnt += (a/A[j])+1;
            a = ((a/A[j])+1)*A[j];
        }
        a = 0;
        ans = min(cnt, ans);
    }
    cout << ans;
}