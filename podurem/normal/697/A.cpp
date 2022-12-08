#include <bits/stdc++.h>

int main() {
    int t, s, x;
    std::cin >> t >> s >> x;
    puts(x - t >= 0 && x - t != 1 && (x - t) % s <= 1 ? "YES" : "NO");
    return 0;
}