#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, z;
    cin >> x >> z;

    if (x == z) {
        cout << "YES\n";
        return 0;
    }

    auto trim = [](string &s) {
        while (s.front() == '0') {
            s.erase(s.begin());
        }
    };

    string x_str = bitset<64>(x).to_string();
    string z_str = bitset<64>(z).to_string();

    trim(x_str), trim(z_str);

    string y_str = x_str;
    reverse(y_str.begin(), y_str.end());
    trim(y_str);

    x_str += '1';
    reverse(x_str.begin(), x_str.end());

    for (int rep = 0; rep < 2; rep++) {
        if (x_str.length() <= z_str.length()) {
            for (int rep0 = 0; rep0 < 2; rep0++) {
                for (int i = 0; i + (int) x_str.length() <= (int) z_str.length(); i++) {
                    if (z_str.substr(i, x_str.length()) == x_str) {
                        int count_zeroes = 0;
                        count_zeroes += count(z_str.begin(), z_str.begin() + i, '0');
                        count_zeroes += count(z_str.begin() + i + x_str.length(), z_str.end(), '0');
                        if (count_zeroes == 0) {
                            return cout << "YES\n", 0;
                        }
                    }
                }
                reverse(x_str.begin(), x_str.end());
            }
        }
        x_str.swap(y_str);
    }

    cout << "NO\n";
    return 0;
}