#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> m;
    cin >> n;
    int diff = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) diff = 1;
        m[a[i]]++;
    }
    if (!diff) {
        cout << "cslnb" << endl;
        return 0;
    }
    int found = 0;
    int num = 0;
    for (auto u : m) {
        if (u.second >= 3) {
            found = 1;
            break;
        }
        if (u.second == 2) {
            num++;
            if (num >= 2) {
                found = 1;
                break;
            }
            if (m.count(u.first - 1) || u.first == 0) {
                found = 1;
                break;
            }
        }
    }
    if (found) {
        cout << "cslnb" << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int foo = (a[i] - i + 1) % 2;
        res ^= foo;
    }
    if (res) {
        cout << "sjfnb" << endl;
    } else {
        cout << "cslnb" << endl;
    }
    return 0;
}