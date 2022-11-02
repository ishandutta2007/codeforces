#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> b(n);

        vector<int> used(2 * n + 1, false);
        bool have_ans = true;
        for(int i = 0;i < n;i++) {
            cin >> b[i];
            if (used[b[i]]) have_ans = false;
            used[b[i]] = true;
        }

        vector<int> res;

        for(int i = 0;i < n;i++) {
            int num = b[i];
            while(num <= 2 * n && used[num]) num++;
            if (num > 2 * n) {
                have_ans = false;
                break;
            }
            res.emplace_back(b[i]);
            res.emplace_back(num);
            used[num] = true;
        }

        if (!have_ans) cout << -1 << endl;
        else {
            for(int i : res)
                cout << i << " ";

            cout << endl;
        }
    }  
}