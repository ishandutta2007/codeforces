#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n, m;
        cin >> n >> m;

        vector<int> p(n + 1);
        vector<int> freq(n);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            freq[(i - p[i] + n) % n]++;
        }

        vector<int> sol;
        for (int k = 0; k < n; k++) {
            if (freq[k] >= n / 3) {
                vector<int> temp(1);
                for (int i = k + 1; i <= n; i++) {
                    temp.push_back(p[i]);
                }
                for (int i = 1; i <= k; i++) {
                    temp.push_back(p[i]);
                }

                int cyc = 0;
                for (int i = 1; i <= n; i++) {
                    if (temp[i] == 0) continue;

                    cyc++;

                    int j = i;
                    while (temp[j] != 0) {
                        int curr = temp[j];
                        temp[j] = 0;
                        j = curr;
                    }
                }

                // cerr << tt << " " << k << " " << cyc << "\n";


                if (n - cyc <= m) {
                    sol.push_back(k);
                }
            }
        }

        cout << sol.size() << " ";
        for (auto itr : sol) {
            cout << itr << " ";
        }
        cout << "\n";
    }
    

    return 0;
}