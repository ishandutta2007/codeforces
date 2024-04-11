#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const double inf = 1e17 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        deque<int> pos[2];

        vector<int> res(n);

        int cnt = 0;

        for(int i = 0;i < n;i++) {
            int num = 1 - s[i] + '0';

            if (pos[num].empty()) {
                cnt++;
                pos[num].emplace_back(cnt);
            }

            pos[1 - num].emplace_back(pos[num].back());
            res[i] = pos[num].back();
            pos[num].pop_back();
        }

        cout << cnt << endl;
        for(int i : res) 
            cout << i << " ";

        cout << endl;
    }
}