#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)3e5 + 3;

int solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    int sum = 0;
    for (int &i : A) {
        cin >> i;
        sum += i;
    }
    for (int k = 0; ; ++k) {
        int sum2 = 0;
        for (int i : A) {
            if (k - i < 0) {
                sum2 = -1e9;
            }
            sum2 += k - i;
        }
        if (sum2 > sum) {
            cout << k << "\n";
            return 0;
        }
    }
    return 0;
}