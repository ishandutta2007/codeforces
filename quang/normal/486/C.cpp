#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n, p, res = 0;
bool ok[N];
string s;

int main() {
    ios_base::sync_with_stdio(0);
  //  fi, fo;
    cin >> n >> p;
    cin >> s;
    s = "Q" + s;
    for(int i = 1; i <= n / 2; i++) {
        if(s[i] != s[n + 1 - i]) {
            if(abs(p - i) > abs(p - (n + 1 - i))) ok[n + 1 - i] = 1;
            else ok[i] = 1;
            int them = abs(s[i] - s[n + 1 - i]);
            them = min(them, 26 - them);
            res += them;
        }
    }
    int vt1 = p, vt2 = p;
    for(int i = 1; i < p; i++)
    if(ok[i]) {
        vt1 = i;
        break;
    }
    for(int i = n; i > p; i--)
    if(ok[i]) {
        vt2 = i;
        break;
    }
    res += abs(p - vt1) + abs(p - vt2);
    res += min(abs(p -vt1), abs(p - vt2));
    cout << res;
    return 0;
}