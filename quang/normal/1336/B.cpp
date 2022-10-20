#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n[3];
pair<int, int> a[N];
int l[3][N], r[3][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc-- ){
        cin >> n[0] >> n[1] >> n[2];
        int cur = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= n[i]; j++) {
                int u;
                cin >> u;
                a[++cur] = {u, i};
            }
        }
        long long res = 4e18;
        sort(a + 1, a + cur + 1);
        for (int i = 1; i <= cur; i++) {
            for (int j = 0; j < 3; j++) l[j][i] = l[j][i - 1];
            l[a[i].second][i] = i;
        }
        for (int i = 0; i < 3; i++) r[i][cur + 1] = cur + 1;
        for (int i = cur; i; i--) {
            for (int j = 0; j < 3; j++) r[j][i] = r[j][i + 1];
            r[a[i].second][i] = i;   
        }

        for (int i = 1; i <= cur; i++) {
            for (int ll = 0; ll < 3; ll++) {
                if (ll == a[i].second) continue;
                for (int rr = 0; rr < 3; rr++) {
                    if (rr == a[i].second || rr == ll) continue;
                    int leftId = l[ll][i];
                    int rightId = r[rr][i];
                    if (leftId == 0 || rightId == cur + 1) continue;
                    auto sqr = [&](int u) {
                        return 1ll * u * u;
                    };
                    res = min(res, sqr(a[i].first - a[leftId].first) + sqr(a[i].first - a[rightId].first) + sqr(a[leftId].first - a[rightId].first));
                }
            }
        }
        cout << res << '\n';
    }   
    return 0;
}