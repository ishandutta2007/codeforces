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

    unordered_set<int> s;

    for (int i = 1; i * (i + 1) <= 2 * n; i++) {
        s.insert((i * (i + 1)) / 2);
    }

    int flag = 0;
    for (int i = 1; i * (i + 1) <= 2 * n; i++) {
        n -= i;
        if (n < 0) break;
        if (s.find(n) != s.end()) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}