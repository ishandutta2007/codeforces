#include <bits/stdc++.h>

int main() {
    int n;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::vector<int> nums;

    std::cin >> n;
    nums.resize(n);
    bool isAllEven = true;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        if (nums[i] % 2 == 1) {
            isAllEven = false;
        }
    }
    //
    if (isAllEven) {
        std::cout << "Second" << std::endl;
    } else {
        std::cout << "First" << std::endl;
    }
    
}