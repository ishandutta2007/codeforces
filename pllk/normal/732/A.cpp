#include <iostream>

using namespace std;

int k, r;
int u, c;

int main() {
    cin >> k >> r;
    while (true) {
        c++;
        u += k;
        if (u%10 == r || u%10 == 0) break;
    }
    cout << c << "\n";
}