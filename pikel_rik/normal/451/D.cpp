#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    int c1_a = 0, c2_a = 0, c1_b = 0, c2_b = 0;
    ll ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            if (i % 2 == 0) {
                ans1 += 1 + c2_a;
                ans2 += c1_a;
                c2_a += 1;
            }
            else {
                ans1 += 1 + c1_a;
                ans2 += c2_a;
                c1_a += 1;
            }
        }
        else {
            if (i % 2 == 0) {
                ans1 += 1 + c2_b;
                ans2 += c1_b;
                c2_b += 1;
            }
            else {
                ans1 += 1 + c1_b;
                ans2 += c2_b;
                c1_b += 1;
            }
        }
    }

    cout << ans2 << " " << ans1 << "\n";
    return 0;
}