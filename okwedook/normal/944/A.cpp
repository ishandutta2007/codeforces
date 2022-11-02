#include <iostream>

using namespace std;
int main() {
    int n, a, b, ans = 0;
    cin >> n >> a >> b, --a, --b;
    while (++ans && a != b) n /= 2, a /= 2, b /= 2;
    if (n == 1) cout << "Final!";
    else cout << ans - 1;
    return 0;
}