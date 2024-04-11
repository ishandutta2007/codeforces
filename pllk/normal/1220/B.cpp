#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
ll t[1111][1111];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t[i][j];
        }
    }
    ll x = t[1][2]*t[1][3]/t[2][3];
    ll a = sqrt(x)-1;
    while (a*a < x) a++;
    cout << a << " ";
    for (int i = 2; i <= n; i++) {
        cout << t[1][i]/a << " ";
    }
    cout << "\n";
}