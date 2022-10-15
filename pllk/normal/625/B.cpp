#include <iostream>

using namespace std;

string t, s;
int n, m;
int d[101010];

int main() {
    cin >> t >> s;
    t = "*"+t;
    n = t.size();
    m = s.size();
    for (int i = 1; i <= n; i++) {
        if (i < m) continue;
        d[i] = 999999999;
        if (t.substr(i-m+1,m) == s) {
            for (int j = 1; j <= m; j++) {
                d[i] = min(d[i],d[i-j]+1);
            }
        } else {
            d[i] = d[i-1];
        }
    }
    cout << d[n] << "\n";
}