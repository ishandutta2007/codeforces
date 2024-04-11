#include <iostream>

#define ll long long int

using namespace std;

int n, m;
ll d;

ll t[200000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i+1];
    }
    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            t[b] = c-d;
        }
        if (a == 2) {
            cin >> b;
            d += b;
        }
        if (a == 3) {
            cin >> b;
            cout << t[b]+d << endl;
        }
    }
}