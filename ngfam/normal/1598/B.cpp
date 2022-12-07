#include <bits/stdc++.h>
#define long long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        vector<vector<int>> a;
        for(int i = 0; i < n; ++i) {
            vector<int> s;
            for(int j = 0; j < 5; ++j) {
                int x; cin >> x;
                s.push_back(x);
            }
            a.push_back(s);
        }

        int flag = 0;

        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) if (i != j) {
                int both = 0, lhs = 0, rhs = 0, either = 0;
                for(int k = 0; k < n; ++k) {
                    if (a[k][i] && a[k][j]) ++both;
                    else if (a[k][i]) ++lhs;
                    else if (a[k][j]) ++rhs;
                    else either++;
                }
                if (either) continue;

                if (max(lhs, rhs) > n / 2) {
                    continue;
                }
                flag = 1;
            }
        }

        cout << (flag ? "YES" : "NO") << "\n";
    }

    return 0;
}