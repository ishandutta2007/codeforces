#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
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
        int ans = 0;
        int cnt = 0;
        for(i=1;i<N-1;i++) {
            ans += (A[i]%2==0?A[i]/2:(A[i]+1)/2);
        }
        int chk = 0;
        for(i=1;i<N-1;i++) {
            if(A[i]==1) cnt++;
            else chk = A[i] % 2;
        }
        if(cnt==N-2||(N==3&&chk==1)) cout << "-1\n";
        else cout << ans << '\n';
    }
}