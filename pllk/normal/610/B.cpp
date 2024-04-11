#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll a[202020];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll p = 1111111111;
    for (int i = 1; i <= n; i++) p = min(p,a[i]);
    int z = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != p) continue;
        int j = i+1;
        if (j == n+1) j = 1;
        int c = 0;
        while (true) {
            if (a[j] == p) break;
            c++;
            j++;
            if (j == n+1) j = 1;
        }
        z = max(z,c);
    }
    cout << p*n+z << "\n";
}