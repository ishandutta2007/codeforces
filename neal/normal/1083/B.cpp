#include <iostream>
using namespace std;
int main() {
    int64_t n, k, i, d = 0, c = 0;
    string s, t;
    cin >> n >> k >> s >> t;
    for (i = 0; i < n; i++)
        c += min(k, (d = min(2 * d + t[i] - s[i], k)) + 1);
    cout << c << '\n';
}