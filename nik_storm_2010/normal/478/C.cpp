#include <iostream>

using namespace std;

int main() {
    long long r, g, b;
    cin >> r >> g >> b;
    if (r > g) swap(r, g);
    if (r > b) swap(r, b);
    if (g > b) swap(g, b);
    cout << min((r + g + b) / 3, r + g) << endl;
    return 0;
}