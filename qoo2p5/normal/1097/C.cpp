#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n;
string s[N];
map<int, pair<int, int>> kek;

void run() {
    cin >> n;
    int corr = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int bal = 0;
        int min_bal = 0;
        for (char c : s[i]) {
            if (c == '(') {
                bal++;
            } else {
                bal--;
            }
            min_bal = min(min_bal, bal);
        }
        if (min_bal >= 0) {
            if (bal == 0) {
                corr++;
            } else {
                kek[bal].first++;
            }
        } else {
            if (min_bal == bal) {
                kek[-bal].second++;
            }
        }
    }
    int ans = corr / 2;
    for (auto& it : kek) {
        ans += min(it.second.first, it.second.second);
    }
    cout << ans << "\n";
}