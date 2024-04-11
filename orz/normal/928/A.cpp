#include <iostream>
#include <vector>

bool check_symbols(char c1, char c2) {
    c1 = static_cast<char>(tolower(c1));
    c2 = static_cast<char>(tolower(c2));
    return c1 == c2 ||
        c1 == '1' && (c2 == 'i' || c2 == 'l') ||
        c1 == 'i' && (c2 == '1' || c2 == 'l') ||
        c1 == 'l' && (c2 == '1' || c2 == 'i') ||
        c1 == '0' && c2 == 'o' ||
        c1 == 'o' && c2 == '0';
}

bool check_strings(std::string &s1, std::string &s2) {
    if (s1.size() == s2.size()) {
        for (int i = 0; i < s1.size(); i++) {
            if (!check_symbols(s1[i], s2[i])) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string login, other;
    int n;
    std::cin >> login >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> other;
        if (check_strings(login, other)) {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";
    return 0;

}