#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int val = min(a / 3, min(b / 2, c / 2));
    int res = val * 7;
    a -= 3 * val;
    b -= 2 * val;
    c -= 2 * val;
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        int aa = a, bb = b, cc = c;
        int j;
        for (j = 0; j < 7; j++) {
            if ((i + j) % 7 == 0 || (i + j) % 7 == 3 || (i + j) % 7 == 6) {
                if (aa == 0) break;
                aa--;
            } else if ((i + j) % 7 == 1 || (i + j) % 7 == 5) {
                if (bb == 0) break;
                bb--;
            } else {
                if (cc == 0) break;
                cc--;
            }
        }
        ans = max(ans, j);
    }
    cout << res + ans << endl;
    return 0;
}