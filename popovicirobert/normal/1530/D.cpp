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
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        } 

        vector<int> sol(n + 1);
        int answer;

        auto Solve = [&](vector<pair<int, int>> a) -> bool {
            set<int> nums;
            set<int> pos;
            for (int i = 1; i <= n; i++) {
                if (nums.find(a[i].first) == nums.end()) {
                    nums.insert(a[i].first);
                    sol[a[i].second] = a[i].first;
                } else {
                    pos.insert(a[i].second);
                }
            }

            answer = nums.size();

            vector<int> vals1, vals2;
            for (int i = 1; i <= n; i++) {
                if (nums.find(i) == nums.end()) {
                    if (pos.find(i) == pos.end()) {
                        vals1.push_back(i);
                    } else {
                        vals2.push_back(i);
                    }
                }
            }

            if (pos.size() == 1 && vals2.size() == 1 && vals2.back() == *pos.begin()) {
                return false;
            }

            if (vals2.size() == 1) {
                pos.erase(vals2.back());
                sol[*pos.begin()] = vals2.back();
                pos.erase(pos.begin());
                pos.insert(vals2.back());
            } else {
                for (int i = 0; i < (int)vals2.size(); i++) {
                    sol[vals2[i]] = vals2[(i + 1) % vals2.size()];
                    pos.erase(vals2[i]);
                }
            }
            for (auto itr : pos) {
                sol[itr] = vals1.back();
                vals1.pop_back();
            }

            return true;
        };

        if (Solve(a) == false) {
            reverse(next(a.begin()), a.end());
            assert(Solve(a) == true);
        }

        cout << answer << "\n";
        for (int i = 1; i <= n; i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}