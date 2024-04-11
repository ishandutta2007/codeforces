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

    int n;
    cin >> n;

    vi x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int sum1 = 0, sum2 = 0;
    pi guy = {-1, -1};

    for (int i = 0; i < n; i++) {
        sum1 += x[i]; sum2 += y[i];
        if (x[i] % 2 != y[i] % 2)
            guy = {x[i], y[i]};
    }

    if (sum1 % 2 != sum2 % 2 or (sum1 % 2 != 0 and sum2 % 2 != 0 and guy.first == -1))
        cout << "-1\n";
    else if (sum1 % 2 != 0)
        cout << "1\n";
    else cout << "0\n";
    return 0;
}