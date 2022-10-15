#include <iostream>

using namespace std;

typedef long long ll;

int n, k;
int a[101010];
int z = 1222333444;
ll c;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < z) z = a[i];
    }
    for (int i = 1; i <= n; i++) {
        if ((a[i]-z)%k != 0) {
            cout << "-1\n";
            return 0;
        }
        c += (a[i]-z)/k;
    }
    cout << c << "\n";
}