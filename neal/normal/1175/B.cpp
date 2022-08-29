#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long OVERFLOW = 1LL << 32;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;
    vector<long long> products = {1};
    long long sum = 0;

    while (L-- > 0) {
        string command;
        cin >> command;

        if (command == "add") {
            sum = min(sum + products.back(), OVERFLOW);
        } else if (command == "for") {
            int n;
            cin >> n;
            products.push_back(min(products.back() * n, OVERFLOW));
        } else if (command == "end") {
            products.pop_back();
        } else {
            assert(false);
        }
    }

    if (sum == OVERFLOW)
        cout << "OVERFLOW!!!" << '\n';
    else
        cout << sum << '\n';
}