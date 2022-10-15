#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[101010];
ll c[50];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i <= 32; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int b = 31; b >= 0; b--) {
                if (a[i]&(1<<b)) {
                    c[b]++;
                    break;
                }
            }
        }
        ll r = 0;
        for (int i = 0; i <= 32; i++) {
            r += c[i]*(c[i]-1)/2;
        }
        cout << r << "\n";
    }
}