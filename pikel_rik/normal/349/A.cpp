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

bool comp(const pi &a, const pi &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 25)
            c1 += 1;
        else if (a[i] == 50) {
            if (c1 == 0) {
                cout << "NO\n";
                return 0;
            }
            c1 -= 1;
            c2 += 1;
        }
        else {
            if (c1 >= 1 and c2 >= 1) {
                c1 -= 1;
                c2 -= 1;
            }
            else if (c1 >= 3) {
                c1 -= 3;
            }
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}