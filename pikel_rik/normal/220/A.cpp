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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b = a;
    sort(all(b));

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            c += 1;
    }

    if (c <= 2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}