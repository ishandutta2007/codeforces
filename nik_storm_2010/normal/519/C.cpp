#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    cout << min(n, (n + m) / 3) << "\n";
    return 0;
}