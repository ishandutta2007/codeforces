#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        set<vector<int>> factors;
        factors.insert(vector<int>(0, 0));
        while(n--) {
            vector<int> now;
            int x; cin >> x;
            for(int i = 2, y = x; i * i <= y; ++i) {
                int cnt = 0;
                while(x % i == 0) {
                    cnt ^= 1;
                    x /= i;
                }
                if (cnt) now.push_back(i);
            }
            if (x > 1) now.push_back(x);
            factors.insert(now);

        }
        if (factors.size() > 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}