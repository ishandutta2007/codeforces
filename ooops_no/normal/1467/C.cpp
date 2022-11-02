#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define ld long double

mt19937 rnd(51);

const int MOD = 1e9 + 7;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<vector<int>> a(3);
    a[0].resize(n1);
    a[1].resize(n2);
    a[2].resize(n3);
    for (int i = 0; i < n1; i++) cin >> a[0][i];
    for (int i = 0; i < n2; i++) cin >> a[1][i];
    for (int i = 0; i < n3; i++) cin >> a[2][i];
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    sort(a[2].begin(), a[2].end());
    vector<int> sum(3);
    for (auto to : a[0]) sum[0] += to;
    for (auto to : a[1]) sum[1] += to;
    for (auto to : a[2]) sum[2] += to;
    int ans = 0;
    for (int i = 0; i < 3; i++){
        for (int j1 = 0; j1 < 3; j1++){
            if (j1 == 0) continue;
            for (int j2 = 0; j2 < 3; j2++){
                if (j2 == 1) continue;
                for (int j3 = 0; j3 < 3; j3++){
                    int now = 0;
                    if (j3 == 2) continue;
                    vector<bool> used(3);
                    vector<int> u{j1, j2, j3};
                    for (auto to : u) used[to] = 1;
                    for (int k = 0; k < 3; k++){
                        if (k == i){
                            now += sum[k];
                            continue;
                        }
                        if (used[k]){
                            if (u[k] == i){
                                now -= sum[k];
                            }
                            else{
                                now += sum[k] - a[k][0];
                                now -= a[k][0];
                            }
                        }
                        else{
                            if (u[k] == i){
                                now -= sum[k];
                            }
                            else{
                                now += sum[k];
                            }
                        }
                    }
                    ans = max(ans, now);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}