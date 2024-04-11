#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll x, y;
string s;
ll c;

int main() {
    cin >> n >> x >> y;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && (i == 0 || s[i-1] == '1')) c++;
    }
    if (c == 0) {
        cout << "0\n";
        return 0;
    }
    ll u1 = c*y;
    ll u2 = y+(c-1)*x;
    cout << min(u1,u2) << "\n";
}