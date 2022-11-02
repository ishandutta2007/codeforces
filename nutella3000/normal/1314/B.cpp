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
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;

const int inf = 1e15;
const int max_n = (1 << 17) + 1;

int n;
bool a[max_n];

vector<vector<int>> f(int left, int right) {
    vector<vector<int>> res(2, vector<int>(2, -inf));
    res[0][0] = 0;

    if (left == right) {
        if (a[left]) res[1][0] = 0;
        return res;
    }

    int mid = (left + right) / 2;

    vector<vector<int>> l = f(left, mid), r = f(mid + 1, right);

    res[1][0] = 1 + max(l[1][0], r[1][0]);
    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 4;j++) {
            int num = l[i / 2][i % 2] + r[j / 2][j % 2];
            int cnt = (i >= 2 || j >= 2) + 2 * (i % 2 == 1 || j % 2 == 1);

            if (i != 0 || j != 0) {
                res[0][1] = max(res[0][1], cnt + num);
            }

            if (i + j >= 3) {
                res[1][1] = max(res[1][1], cnt + num);
            }
        }
    }

    return res;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int k;
    cin >> n >> k;
    n = (1 << n);

    for(int i = 0;i < k;i++) {
        int v;
        cin >> v;
        v--;
        a[v] = true;
    }

    vector<vector<int>> res = f(0, n - 1);


    if (k == 0) cout << 0;
    else cout << max(res[1][1], max(res[1][0], res[0][1])) + 1;
}