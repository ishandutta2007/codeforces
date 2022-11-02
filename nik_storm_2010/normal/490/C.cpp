#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
const int N = 1e6 + 10;

int power[N];

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length(), a, b;
    cin >> a >> b;
    power[0] = 1 % b;
    for (int i = 1; i < N; i++) power[i] = (power[i - 1] * 10) % b;
    int mod1 = 0, mod2 = 0;
    for (int i = 0; i < n; i++) mod2 = (mod2 * 10 + s[i] - '0') % b;
    for (int i = 0; i < n - 1; i++) {
        mod1 = (mod1 * 10 + s[i] - '0') % a;
        mod2 = (mod2 - (s[i] - '0') * power[n - i - 1]) % b;
        if (mod1 == 0 && mod2 == 0 && s[i + 1] != '0') {
            cout << "YES\n";
            for (int j = 0; j <= i; j++) cout << s[j];
            cout << "\n";
            for (int j = i + 1; j < n; j++) cout << s[j];
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}