#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll m;
int r[5555];

int main() {
    cin >> n >> m;
    ll u = 0;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        r[i] = i;
        u += (i-1)/2;
        if (u > m) {
            if (i%2 == 0) r[i]++;
            while (u > m) {r[i] += 2; u--;}
        }
        if (u == m) {
            int x = 100000;
            for (int j = i+1; j <= n; j++) {
                r[j] = x+1;
                x += 100000;
            }
            ok = true;
            break;
        }
    }
    if (ok) {
        for (int i = 1; i <= n; i++) cout << r[i] << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}