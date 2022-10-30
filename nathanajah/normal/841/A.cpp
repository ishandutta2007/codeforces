#include <bits/stdc++.h>

int main() {
    std::iostream::sync_with_stdio(false);
    std::vector<char> chars(26);
    int n, k;
    std::string s;
    std::iota(chars.begin(), chars.end(), 'a');
    std::cin >> n >> k;
    std::cin >> s;
    std::vector<int> counts(26);
    std::transform(
        chars.begin(),
        chars.end(),
        counts.begin(),
        [s](char c){
            return static_cast<int>(std::count(s.begin(), s.end(), c));
        }
    );
    int max_cnt = *(std::max_element(counts.begin(), counts.end()));
    if (max_cnt <= k) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}