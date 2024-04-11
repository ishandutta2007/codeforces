#include <iostream>

using namespace std;

typedef long long ll;

int n, m;
ll c1[5], c2[5];
ll z;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) c1[i%5]++;
    for (int i = 1; i <= m; i++) c2[i%5]++;
    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
            if ((a+b)%5 != 0) continue;
            z += c1[a]*c2[b];
        }
    }
    cout << z << "\n";
}