#include <iostream>

using namespace std;

#define ll long long
#define M 1000000007

string s;
int n;
ll d[1010101][5];
ll t;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    if (s[0] == '0' || s[0] == '?') {
        d[0][0] = 1;
    }
    if (s[0] == '1' || s[0] == '?') {
        d[0][2] = 1;
    }
    if (s[0] == '*' || s[0] == '?') {
        d[0][4] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '0' || s[i] == '?') {
            d[i][0] = (d[i-1][0]+d[i-1][1])%M;
        }
        if (s[i] == '1' || s[i] == '?') {
            d[i][1] = d[i-1][4];
            d[i][2] = (d[i-1][0]+d[i-1][1])%M;
        }
        if (s[i] == '2' || s[i] == '?') {
            d[i][3] = d[i-1][4];
        }
        if (s[i] == '*' || s[i] == '?') {
            d[i][4] = (d[i-1][2]+d[i-1][3])%M;
            d[i][4] = (d[i-1][4]+d[i][4])%M;
        }
    }
    t += d[n-1][0];
    t %= M;
    t += d[n-1][1];
    t %= M;
    t += d[n-1][4];
    t %= M;
    cout << t << endl;
}