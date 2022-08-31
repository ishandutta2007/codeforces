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
const int N = 1e5;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, x, y;
    cin >> n >> l >> x >> y;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool flag1 = false, flag2 = false;

    for (int i = 0; i < n; i++) {
        int temp = lower_bound(all(a), x + a[i]) - a.begin();
        if (temp != n and a[temp] == x + a[i]) {
            flag1 = true;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        int temp = lower_bound(all(a), y + a[i]) - a.begin();
        if (temp != n and a[temp] == y + a[i]) {
            flag2 = true;
            break;
        }
    }

    if (flag1 and flag2) {
        cout << "0\n";
        return 0;
    }

    if (!flag1 and flag2) {
        cout << "1\n" << x << "\n";
        return 0;
    }

    if (flag1 and !flag2) {
        cout << "1\n" << y << "\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int pos1 = lower_bound(a.begin(), a.begin() + i, a[i] + x - y) - a.begin();
        int pos2 = lower_bound(a.begin(), a.begin() + i, a[i] - x - y) - a.begin();

        if (pos1 != i and a[pos1] == a[i] + x - y) {
            if (a[pos1] + y < l) {
                cout << "1\n" << a[pos1] + y << "\n";
                return 0;
            }
            if (a[pos1] - x > 0) {
                cout << "1\n" << a[pos1] - x << "\n";
                return 0;
            }
        }

        if (pos2 != i and a[pos2] == a[i] - x - y) {
            cout << "1\n" << a[pos2] + x << "\n";
            return 0;
        }
    }

    cout << "2\n" << x << " " << y << "\n";
    return 0;
}