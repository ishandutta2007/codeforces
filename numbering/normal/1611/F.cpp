#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[200005];
int B[200005];
typedef pair<int,int> P;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, s;
        cin >>N >> s;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=1;i<=N;i++) B[i] = B[i-1] + A[i-1];
        j = 0;
        int ans = 0, s2, e2;
        for(i=1;i<=N;i++) {
            while(B[i] - B[j] + s < 0) j++;
            //cout << i << ' ' <<j << '\n';
            if(ans < i - j) {
                ans = i - j;
                s2 = j + 1;
                e2 = i;
            }
        }
        if(ans != 0) cout << s2 << ' ' << e2 << '\n';
        else cout << "-1\n";
    }
}