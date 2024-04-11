#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;
/*  1 3 5 2


*/

int solve() {

    array<int, 4> cnt;
    for (int i = 0; i < 4; i++) cin >> cnt[i];
    int N = cnt[0] + cnt[1] + cnt[2] + cnt[3];
    vector<int> ans;

    for (int s = 0; s < 4; s++) {
        ans.clear();
        int cur = s;
        array<int, 4> a = cnt, tt = {0, 0, 0, 0};
        while (ans.size() < N) {
            ans.emplace_back(cur);
            a[cur]--;
            if (cur == 0) {
                cur++;
            } else if (cur == 3) {
                cur--;
            } else {
                if (a[cur - 1] <= 0) {
                    cur++;
                } else if (a[cur + 1] <= 0) {
                    cur--;
                } else if (a[cur - 1] < a[cur + 1]) {
                    cur--;
                } else if (a[cur - 1] > a[cur + 1]) {
                    cur++;
                } else {
                    if (cur == 1) {
                        cur--;
                    } else {
                        cur++;
                    }
                }
            }
        }
        bool can = true;        
        for (int i = 0; i < N; i++) {
            tt[ans[i]]++;
        }
        for (int i = 0; i < 4; i++) {
            // cout << cnt[i] << tt[i] << " ";
            if (cnt[i] != tt[i]) {
                can = false;
                break;
            }
        }
        if (!can) continue;
        for (int i = 1; i < N; i++) {
            if (abs(ans[i] - ans[i - 1]) != 1) {
                can = false;
                break;
            }
        }
        if (!can) continue;
        cout << "YES\n";
        for (auto i : ans) cout << i << " ";
        cout << "\n";
        ans.clear();
        return 0;
    }

    cout << "NO\n";
    return 0;


}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Testcase = 1;
    
    #ifdef TESTCASE
    cin >> Testcase;
    #endif

    for (int tc = 1; tc <= Testcase; tc++) {
        solve();
    }

    return 0;
}