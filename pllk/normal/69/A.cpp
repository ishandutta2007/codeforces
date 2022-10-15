#include <iostream>

using namespace std;

int n;
int a, b, c;
int aa, bb, cc;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        aa += a; bb += b; cc += c;
    }
    if (aa == 0 && bb == 0 && cc == 0) cout << "YES\n";
    else cout << "NO\n";
}