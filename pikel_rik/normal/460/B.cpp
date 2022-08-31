#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int d(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int power(int x, int a) {
    int ans = 1;
    for (int i = 0; i < a; i++) ans *= x;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    vi ans;

    for (int i = 1; i <= 81; i++) {
        ll x = b * (ll)power(i, a) + c;
        if (d(x) == i and x < 1e9 and x > 0)
            ans.push_back(x);
    }

    sort(all(ans));

    cout << ans.size() << "\n";
    for (int an : ans) {
        cout << an << " ";
    }
    return 0;
}