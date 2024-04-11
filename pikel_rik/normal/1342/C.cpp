#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        ll a, b, q;
        cin >> a >> b >> q;

        ll num = (a * b) / __gcd(a, b);

        vector<int> isok(num + 1, 1);
        isok[0] = 0;

        for (int i = 1; i <= num; i++) {
            if ((i % a) % b == (i % b) % a)
                isok[i] = 0;
        }

        for (int i = 2; i <= num; i++) {
            isok[i] += isok[i-1];
        }

        while (q--) {
            ll l, r;
            cin >> l >> r;

            ll l1 = l, r1 = r;

            r -= r % num;
            if (l % num != 0) l += num - l % num;

            if (l > r) {
                cout << isok[r1 % num] - (l1 % num == 0 ? 0 : isok[l1 % num - 1]) << " ";
                continue;
            }

            cout << (l1 % num == 0 ? 0 : isok[num] - (l1 % num == 0 ? 0 : isok[l1 % num - 1])) + (r1 % num == 0 ? 0 : isok[r1 % num] - isok[0]) + ((r - l)/num) * (isok[num] - isok[0]) << " ";
        }
        cout << "\n";
    }
    return 0;
}