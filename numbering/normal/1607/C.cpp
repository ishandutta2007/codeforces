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
        int N;
        cin >> N;
        int i, j;
        priority_queue<int,vector<int>, greater<int> > PQ;
        for(i=0;i<N;i++) {
            cin >> j;
            PQ.push(j);
        }
        int ma = PQ.top();
        int mi = 0;
        while(PQ.size() >= 2) {
            int t = PQ.top();
            mi += t - mi;
            PQ.pop();
            ma = max(ma, PQ.top() - mi);
        }
        cout << ma << '\n';
    }
}