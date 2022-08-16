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

string s;
int c, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> c;
    n = s.length();

    int best = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; i + j - 1 < n; j++) {
            string temp = s.substr(i, j);
            bool flag = false;

            if (temp.length() % 2 == 0) {
                bool flg = true;

                for (int k = 0; k < temp.length() / 2; k++) {
                    if (temp[k] != temp[k + temp.length() / 2]) {
                        flg = false;
                        break;
                    }
                }

                if (flg) best = max(best, (int)temp.length() / 2);
            }

            for (int k = i + j; k < n; k++) {
                if (s[k] != temp[k - i - j]) {
                    flag = true;
                    break;
                }
            }

            if (!flag and temp.length() - (n - i - j) <= c) {
                int now = temp.length();
                int num = 2;
                while (num * temp.length() - (n - i - j) <= c) {
                    if (temp.length() % 2 == 0)
                        now += temp.length() / 2;
                    else if (num % 2 != 0)
                        now += temp.length();
                    num += 1;
                }
                best = max(best, now);
            }
        }
    }

    if (c > n) {
        best = max(best, (n + c) / 2);
    }

    cout << 2 * best << "\n";
    return 0;
}