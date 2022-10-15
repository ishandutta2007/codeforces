#include <iostream>

using namespace std;

typedef long long ll;

int n;
int x[202020];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    ll r = 0;
    for (int i = 1; i <= n; i++) {
        int u;
        for (int k = 30; k >= 0; k--) {
            if (x[i]&(1<<k)) {u = k; break;}
        }
        ll s = 0;
        for (int j = i+1; j+1 <= n; j++) {
            s += x[j];
            if (s == (x[i]^x[j+1]) && x[i] > x[j+1]) {
                r++;
                // cout << i << " " << j+1 << "\n";
            }
            if (s >= (1<<(u+1))) break;
        }
    }
    for (int i = n; i >= 1; i--) {
        int u;
        for (int k = 30; k >= 0; k--) {
            if (x[i]&(1<<k)) {u = k; break;}
        }
        ll s = 0;
        for (int j = i-1; j-1 >= 1; j--) {
            s += x[j];
            if (s == (x[i]^x[j-1]) && x[i] > x[j-1]) {
                r++;
                // cout << i << " " << j-1 << "\n";
            }
            if (s >= (1<<(u+1))) break;
        }
    }
    cout << r << "\n";
}