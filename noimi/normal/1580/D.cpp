#include <bits/stdc++.h>
int x, a[4444], n, m;
std::vector<long long> dfs(int l, int r) {
    if(l == r) return {0};
    int k = std::min_element(a + l, a + r) - a;
    auto L = dfs(l, k), R = dfs(k + 1, r);
    std::vector<long long> res(r - l + 1, -LLONG_MAX);
    for(int i = 0; i < L.size(); i++)
        for(int j = 0; j < R.size(); j++)
            for(int t = 0; t < 2; t++) res[i + j + t] = std::max(res[i + j + t], L[i] + R[j] - (long long)(i * j * 2 + t * (1 - m + i * 2 + j * 2)) * a[k]);
    return res;
}
int main() {
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) std::cin >> a[i];
    std::cout << dfs(0, n)[m] << std::endl;
}