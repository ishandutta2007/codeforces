#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;

    int res = a + b;
    res %= n;
    res += n;
    res %= n;
    if (res == 0) res = n;

    cout << res;

    return 0;
}