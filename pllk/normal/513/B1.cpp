#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int p[100];
int v[100];
int uu;
int c;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i+1;
    do {
        int u = 0;
        for (int i = 0; i < n; i++) {
            int z = p[i];
            for (int j = i; j < n; j++) {
                z = min(z, p[j]);
                u += z;
            }
        }
        if (u > uu) {
            uu = u;
            c = 0;
        }
        if (u == uu) {
            c++;
            if (c == m) {
                for (int i = 0; i < n; i++) v[i] = p[i];
            }
        }
    } while (next_permutation(p, p+n));
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n";
}