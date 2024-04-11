#include <iostream>

using namespace std;

typedef long long ll;

#define M 1000000007

ll pot(int a, int b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u *= u;
    u %= M;
    if (b%2 == 1) u *= a;
    u %= M;
    return u;
}

ll inv(int x) {
    return pot(x,M-2);
}

ll tf[505050];
ll ti[505050];

ll ncr(int a, int b) {
    if (b > a) return 0;
    ll u = tf[a];
    u *= ti[b];
    u %= M;
    u *= ti[a-b];
    u %= M;
    return u;
}

ll laske(int a, int b) {
    if (a > b) swap(a,b);
    int z = min(a,b);
    ll u = ncr(a+b,z);
    return u;
}

string s;
int n;

int main() {
    tf[0] = 1;
    for (int i = 1; i <= 500000; i++) tf[i] = (tf[i-1]*i)%M;
    ti[500000] = inv(tf[500000]);
    for (int i = 499999; i >= 0; i--) {
        ti[i] = (ti[i+1]*(i+1))%M;
    }
    cin >> s;
    n = s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) if (s[i] == ')') b++;
    ll u = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i-1] == '(') u += laske(a,b)-laske(a-1,b);
        u %= M;
        if (s[i] == '(') a++;
        if (s[i] == ')') b--;
    }
    if (u < 0) u += M;
    cout << u << "\n";
}