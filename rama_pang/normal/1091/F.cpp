#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<lint> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    string s;
    cin >> s;
    lint ans = 0;
    lint stamina = 0;
    bool meetW = false;
    lint convertGrass = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            stamina += l[i];
            ans += l[i] * 5;
            convertGrass += 2 * l[i];
        }
        if (s[i] == 'W') {
            stamina += l[i];
            ans += l[i] * 3;
            meetW = true;
        }
        if (s[i] == 'L') {
            ans += l[i] * 1;
            stamina -= l[i];
            if (stamina < 0) {
                ans += (-stamina) * (meetW ? 3 : 5);
                stamina = 0;
            }
        }
        convertGrass = min(stamina, convertGrass);
    }

    if (stamina > 0) {
        ans -= (5 - 1) * (convertGrass) / 2;
        ans -= (3 - 1) * (stamina - convertGrass) / 2;
    }

    cout << ans << "\n";
    return 0;
}