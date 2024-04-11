#include <iostream>

#define J 1000000007
#define ll long long int

using namespace std;

int n;
int x, y;

ll K[1000];

ll M[1000][1000];
int V[1000][1000];

ll F(int a, int b) {
    if (a == 0 && b == 0) return 1;
    if (b == 0) return K[a];
    if (V[a][b]) return M[a][b];
    ll t = 0;
    if (a > 0) t += a*F(a-1,b);
    t %= J;
    t += F(a,b-1);
    t %= J;
    if (b > 1) {
        ll k = b-1;
        for (int i = 0; i <= a; i++) {
            t += k*F(a-i,b-2);
            k *= (a-i);
            t %= J;
            k %= J;
        }
    }
    V[a][b] = 1;
    M[a][b] = t%J;
    return M[a][b];
}

int main() {
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) x++;
        if (a == 2) y++;
    }
    K[0] = 1;
    for (int i = 1; i < 1000; i++) K[i] = (i*K[i-1])%J;
    cout << F(y,x)%J << endl;
}