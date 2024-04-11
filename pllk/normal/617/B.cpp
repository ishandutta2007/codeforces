#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[111];
ll d[111];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    d[0] = 1;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = i; j >= 1; j--) {
            if (a[j]) c++;
            if (c == 1) d[i] += d[j-1];
        }
    }
    cout << d[n] << "\n";
}