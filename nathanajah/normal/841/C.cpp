#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::vector<int> a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::vector<std::pair<int, int> > indexedB;

    std::cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        indexedB.emplace_back(i, b[i]);
    }

    std::sort(indexedB.begin(), indexedB.end(),
            [](std::pair<int, int> a, std::pair<int, int> b)
            {return a.second > b.second;}
    );

    std::sort(a.begin(), a.end());

    std::vector<std::tuple<int, int, int>> merged;

    for (int i = 0; i < n; i++) {
        merged.emplace_back(indexedB[i].first, indexedB[i].second, a[i]);
    }

    sort(merged.begin(), merged.end());

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << std::get<2>(merged[i]);
    }
    std::cout << std::endl;


}