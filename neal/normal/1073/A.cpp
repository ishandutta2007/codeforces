#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    for (int start = 0; start < n; start++) {
        vector<int> freq(256, 0);
        int most = 0;

        for (int i = start; i < n; i++) {
            most = max(most, ++freq[str[i]]);

            if (2 * most <= i + 1 - start) {
                cout << "YES" << '\n';
                cout << str.substr(start, i + 1 - start) << '\n';
                return 0;
            }
        }
    }

    cout << "NO" << '\n';
}