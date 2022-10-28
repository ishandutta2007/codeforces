#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

bool qry(int c) {
    cout << "? " << c+1 << endl;
    char ans; cin >> ans;
    return ans == 'Y';
}
void reset() {
    cout << 'R' << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    int b = max(1, k / 2);
    vector<bool> head(n, 1);
    for (int i = 0; i < n; i++) {
        if (qry(i)) {
            head[i] = 0;
        }
    }
    int cnt_b = n / b;
    for (int i = 0; i < cnt_b; i++) {
        for (int j = i+1; j < cnt_b; j++) {
            reset();
            for (int k = 0; k < b; k++) qry(i * b + k);
            for (int k = 0; k < b; k++) if (head[j * b + k]) {
                if (qry(j * b + k)) {
                    head[j * b + k] = 0;
                }
            }
        }
    }
    cout << "! " << std::accumulate(head.begin(), head.end(), 0) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}