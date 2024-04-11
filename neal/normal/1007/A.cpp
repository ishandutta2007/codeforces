#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    int total = 0, smaller = 0;

    for (auto it = freq.begin(); it != freq.end(); it++) {
        int take = min(smaller, it->second);
        total += take;
        smaller += it->second - take;
    }

    cout << total << '\n';
    return 0;
}