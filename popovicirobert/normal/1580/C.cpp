#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;

constexpr int MAXN = (int)2e5;
constexpr int BUCK = 400;

int sp[BUCK + 1][MAXN + 1];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> sp2(m + 1);
    vector<int> first(n + 1);

    for (int i = 1; i <= m; i++) {
        int op, id;
        cin >> op >> id;

        if (op == 1) {
            first[id] = i + x[id];
            if (x[id] + y[id] > BUCK) {
                int t = first[id];
                while (t <= m) {
                    sp2[t]++;
                    if (t + y[id] <= m) {
                        sp2[t + y[id]]--;
                    }
                    t += x[id] + y[id];
                }
            } else {
                for (int t = i + x[id]; t <= min(m, first[id] + y[id] - 1); t++) {
                    sp[x[id] + y[id]][t]++;
                }
            }
        } else {
            if (x[id] + y[id] > BUCK) {
                int t = first[id];
                while (t <= m) {
                    sp2[max(t, i)]--;
                    if (t + y[id] <= m) {
                        sp2[max(i, t + y[id])]++;
                    }
                    t += x[id] + y[id];
                }
            } else {
                for (int t = max(i - 1, min(m, first[id] + y[id] - 1)); t >= max(first[id], i - x[id] - y[id]); t--) {
                    int rem = (t - first[id]) % (x[id] + y[id]) + 1;
                    if (rem <= y[id]) {
                        sp[x[id] + y[id]][t]--;
                    }
                } 
            }
        }

        sp2[i] += sp2[i - 1];

        int curr = sp2[i];
        for (int j = 1; j <= BUCK; j++) {
            if (i >= j) {
                sp[j][i] += sp[j][i - j];
            }
            curr += sp[j][i];
        }

        cout << curr << "\n";
    }


    return 0;
}