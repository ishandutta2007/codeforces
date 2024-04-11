#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> s(n);
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (s[y] == 3) s1--;
        if (y > 0) {
            if ((s[y] | s[y - 1])== 3) s2--;
        }
        if (y < n - 1) {
            if ((s[y] | s[y + 1])== 3) s2--;
        }

        s[y] ^= (1 << x);

        if (s[y] == 3) s1++;
        if (y > 0) {
            if ((s[y] | s[y - 1])== 3) s2++;
        }
        if (y < n - 1) {
            if ((s[y] | s[y + 1])== 3) s2++;
        }

        if (s1 == 0 && s2 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}