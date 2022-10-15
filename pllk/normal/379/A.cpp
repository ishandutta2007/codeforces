#include <iostream>

using namespace std;

int a, b, c;
int v;

int main() {
    cin >> a >> b;
    v = a;
    c += a;
    while (c >= b) {
        int x = c/b;
        v += x;
        c -= (c/b)*b;
        c += x;
    }
    cout << v << endl;
}