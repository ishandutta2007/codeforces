#include<iostream>
#include<string>

using namespace std;
const long long mod = 1000000007;
const int N = 5000 + 10;

long long f[N][N];

int main() {
    string s, t;
    cin >> s >> t;
    int ss = s.size(), tt = t.size();
    for (int i = ss - 1; i >= 0; i--)
        for (int j = tt - 1; j >= 0; j--) {
            f[i][j] = f[i][j + 1];
            if (s[i] == t[j]) f[i][j] = (f[i][j] + f[i + 1][j + 1] + 1) % mod;
        }
    long long ans = 0;
    for (int i = 0; i < ss; i++) ans = (ans + f[i][0]) % mod;
    cout << ans;
    return 0;
}