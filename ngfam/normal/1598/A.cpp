#include <bits/stdc++.h>
#define long long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        string a[2]; cin >> a[0] >> a[1];
        int pos = 0, ans = 0;

        for(int i = 0; i < n; ++i) {
            if (a[0][i] == '1' && a[1][i] == '1') {
                pos = -1;
                break;
            }
        }

        if (pos == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

    }

    return 0;
}