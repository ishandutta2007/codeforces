#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 1) cout << 7, n -= 3;
    for (int i = n / 2; i < n; ++i) cout << 1;
    return 0;
}