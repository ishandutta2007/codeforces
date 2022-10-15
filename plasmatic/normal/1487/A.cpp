// ./a-arena.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        int mn = INF, cnt = 0;
        for (auto &x : v) {
            cin >> x;
            if (x < mn) {
                mn = x;
                cnt = 1;
            }
            else if (x == mn)
                cnt++;
        }
        cout << (N-cnt) << '\n';
    }

    return 0;
}