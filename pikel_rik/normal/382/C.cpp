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

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));

    if (n == 1) {
        cout << "-1\n";
        return 0;
    }
    else if (n == 2) {
        if (a[1] == a[0]) cout << "1\n" << a[1];
        else if ((a[1] - a[0]) % 2 == 0)
            cout << "3\n" << a[0] - (a[1] - a[0]) << " " << (a[1] + a[0]) / 2 << " " << a[1] + (a[1] - a[0]);
        else cout << "2\n" << a[0] - (a[1] - a[0]) << " " << a[1] + (a[1] - a[0]);
        return 0;
    }

    vi diff(n - 1);
    for (int i = 1; i < n; i++) diff[i-1] = a[i] - a[i-1];

    int num1 = *max_element(all(diff)), num2 = *min_element(all(diff));

    if (num2 == 0 and num1 != num2) {
        cout << "0\n";
        return 0;
    }
    else if (num2 == 0 and num1 == num2) {
        cout << "1\n" << a[0];
        return 0;
    }

    if (num1 != num2 and num1 != 2 * num2) {
        cout << "0\n";
        return 0;
    }

    if (num1 == num2) {
        cout << "2\n";
        cout << a[0] - (a[1] - a[0]) << " " << a[n-1] + (a[n-1] - a[n-2]) << "\n";
        return 0;
    }
    int c1 = 0, c2 = 0;

    for (int i = 0; i < n - 1; i++) {
        if (diff[i] != num1 and diff[i] != num2) {
            cout << "0\n";
            return 0;
        }
        else {
            if (diff[i] == num1) c1 += 1;
            else c2 += 1;
        }
    }

    if (c1 > 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if (diff[i] == num1) {
            cout << "1\n" << (a[i] + a[i+1]) / 2;
            return 0;
        }
    }
    return 0;
}