#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 2 * 1e18;
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
        int mx = 0, ax = 0, my = 0, ay = 0;
        int x = 0, y = 0;
        int i;
        for(i=0;i<s.length();i++) {
            if(s[i] == 'D') y--;
            if(s[i] == 'R') x++;
            if(s[i] == 'L') x--;
            if(s[i] == 'U') y++;
            mx = min(x, mx);
            my = min(y, my);
            ax = max(x, ax);
            ay = max(y, ay);
            if(ay - my >= N) {
                if(s[i] == 'D') my++;
                break;
            }
            if(ax - mx >= M) {
                if(s[i] == 'L') mx++;
                break;
            }
        }
        cout << N+1 - (1 - my) << ' ' << 1-mx << '\n';
    }
}