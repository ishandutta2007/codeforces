#include <iostream>

using namespace std;

#define M 1000000007

typedef long long ll;

ll u[128];
string s;

int main() {
    for (int a = 0; a < 64; a++) {
        for (int b = 0; b < 64; b++) {
            u[a&b]++;
        }
    }
    cin >> s;
    ll z = 1;
    for (int i = 0; i < s.size(); i++) {
        int x;
        if (s[i] >= '0' && s[i] <= '9') x = s[i]-'0';
        if (s[i] >= 'A' && s[i] <= 'Z') x = s[i]-'A'+10;
        if (s[i] >= 'a' && s[i] <= 'z') x = s[i]-'a'+36;
        if (s[i] == '-') x = 62;
        if (s[i] == '_') x = 63;
        z *= u[x];
        z %= M;
    }
    cout << z << "\n";
}