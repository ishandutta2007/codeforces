// ./b-almost-sorted.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1, LG = 62;
int N;
ll K;

void solve() {
    cin >> N >> K;
    if (N < LG && K > (1LL << (N-1))) cout << "-1\n";
    else {
        vector<bool> fl(N);
        for (auto i = 0; i < min(N, LG); i++) {
            if (((K-1) >> i) & 1) {
                fl[N-1-i] = true;
            }
        }

        vector<int> ans{1};
        for (auto i = 1; i < N; i++) {
            if (fl[i]) {
                int th = ans.back();
                for (auto &x : ans)
                    if (x >= th) x++;
                ans.push_back(th);
            }
            else ans.push_back(ans.size()+1);
        }

        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}