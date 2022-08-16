#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi count(8);
    for (int i = 0; i < n; i++) {
        count[a[i]] += 1;
    }

    if (count[5] > 0 or count[7] > 0 or (count[4] > count[2] or count[3] > count[6] or count[6] + count[4] != count[2] + count[3] or count[2] + count[3] != count[4] + count[6]))
        cout << "-1\n";
    else if (count[1] != n/3)
        cout << "-1\n";
    else {
        for (int i = 0; i < count[4]; i++) {
            cout << "1 2 4\n";
        }
        count[2] -= count[4];
        for (int i = 0; i < count[2]; i++) {
            cout << "1 2 6\n";
        }
        for (int i = 0; i < count[3]; i++) {
            cout << "1 3 6\n";
        }
    }
    return 0;
}