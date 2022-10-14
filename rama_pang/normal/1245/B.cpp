#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T; while (T--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s; cin >> s;
        int aa = 0, bb = 0, cc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') bb++;
            if (s[i] == 'P') cc++;
            if (s[i] == 'S') aa++;
        }
        
        string k = s;
        int win = 0;
        // win += (a >= aa)? aa : a;
        if ((min(a, aa) + min(b, bb) + min(c, cc)) >= ceil(double(n) / 2)) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) k[i] ='-';

            for (int i = 0; i < n; i++) {
                if (s[i] == 'R' && b > 0) {
                    k[i] = 'P';
                    b--;
                } else if (s[i] == 'P' && c > 0) {
                    k[i] = 'S';
                    c--;
                } else if (s[i] == 'S' && a > 0) {
                    k[i] = 'R';
                    a--;
                }
            }
            for (int i = 0; i < n; i++) {
                if (a > 0 && k[i] == '-') {
                    k[i] = 'R';
                    a--;
                } else if (b > 0 && k[i] == '-') {
                    k[i] = 'P';
                    b--;
                } else if (c > 0 && k[i] == '-') {
                    k[i] = 'S';
                    c--;
                }
            }
            cout << k;
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

}