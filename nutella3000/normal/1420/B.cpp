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
const int max_n = 3e5 + 1;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cnt(30);

        for(int i = 0;i < n;i++) {
            int v;
            cin >> v;
            int num = 0;
            while(v > 1) {
                num++;
                v /= 2;
            }
            cnt[num]++;
        }

        int res = 0;
        for(int i = 0;i < 30;i++)
            res += cnt[i] * (cnt[i] - 1) / 2;

        cout << res << endl;
    }
}