#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll b[202020];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    cout << b[1] << " ";
    ll r = b[1];
    for (int i = 2; i <= n; i++) {
        ll u = b[i]+r;
        cout << u << " ";
        r = max(r,u);
    }
    cout << "\n";
}