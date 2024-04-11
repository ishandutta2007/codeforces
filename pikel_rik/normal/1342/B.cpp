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
        string t;
        cin >> t;

        vi count(2);
        for (char i : t) {
            count[i - '0'] += 1;
        }

        if (count[0] == 0 or count[1] == 0) {
            cout << t << "\n";
            continue;
        }

        if (t[0] == '1') {
            for (int i = 0; i < 2 * t.length(); i++)
                if (i % 2 == 0) cout << "1";
                else cout << "0";
        }
        else {
            for (int i = 0; i < 2 * t.length(); i++)
                if (i % 2 == 0) cout << "0";
                else cout << "1";
        }

        cout << "\n";
    }
    return 0;
}