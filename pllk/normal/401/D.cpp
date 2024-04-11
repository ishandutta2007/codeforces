#include <iostream>

using namespace std;

#define ll long long

string s;
int n;
int m;
ll d[1<<18][100];

ll x(int k) {
    ll t = 1;
    for (int i = 1; i <= k; i++) t *= i;
    return t;
}

int y(int k) {
    int t = 0;
    for (int i = 0; i < n; i++) if (s[i] == '0'+k) t++;
    return t;
}

int main() {
    cin >> s >> m;
    n = s.size();
    d[0][0] = 1;
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < m; j++) {
            if (!d[i][j]) continue;
            for (int b = 0; b < n; b++) {
                if (i&(1<<b)) continue;
                if (i == 0 && s[b] == '0') continue;
                d[i|(1<<b)][(j*10+s[b]-'0')%m] += d[i][j];
            }
        }
    }
    ll z = d[(1<<n)-1][0];
    for (int i = 0; i <= 10; i++) z /= x(y(i));
    cout << z << endl;
}