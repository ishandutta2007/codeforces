#include <iostream>
#include <vector>
#include <algorithm>

int n, k;

int from(int index) {
    return std::max(0, index - k);
}

int to(int index) {
    return std::min(n - 1, index + k);
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> k;
    std::vector<int> link(static_cast<unsigned int>(n));
    for (int i = 0; i < n; i++) {
        std::cin >> link[i];
        link[i]--;
    }

    std::vector<int> count(static_cast<unsigned int>(n), 0);

    for (int i = 0; i < n; i++) {
        int p = link[i];
        if (p == -1) {
            count[i] = to(i) - from(i) + 1;
        } else {
            count[i] = count[p] + to(i) - std::max(from(i) - 1, to(p));
        }

        std::cout << count[i] << ' ';
    }

    std::cout << '\n';
    return 0;

}