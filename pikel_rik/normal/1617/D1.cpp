#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        auto query = [](int a, int b, int c) -> int {
            cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
            int ans;
            cin >> ans;
            return ans;
        };

        vector<bool> impostor(n);

        int prev_ans = -1, ii = -1, jj = -1;
        for (int i = 0; i + 2 < n; i++) {
            int cur_ans = query(i, i + 1, i + 2);
            if (prev_ans != -1 && cur_ans != prev_ans) {
                ii = i, jj = i + 1;
                break;
            }
            prev_ans = cur_ans;
        }

        assert(ii != -1 && jj != -1);

        int other_ii = -1, other_jj = -1;
        for (int i = 0; i < n; i++) {
            if (i != ii && i != jj) {
                int q = query(i, ii, jj);
                if (q == 0) {
                    impostor[i] = true;
                    other_ii = i;
                } else {
                    impostor[i] = false;
                    other_jj = i;
                }
            }
        }

        assert(other_ii != -1 && other_jj != -1);

        impostor[ii] = !query(other_ii, other_jj, ii);
        impostor[jj] = !query(other_ii, other_jj, jj);

        vector<int> final;
        for (int i = 0; i < n; i++) {
            if (impostor[i]) {
                final.push_back(i);
            }
        }

        cout << "! " << final.size() << ' ';
        for (auto imp : final) {
            cout << imp + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}