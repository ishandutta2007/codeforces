#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
using namespace std;

int N, Q;
map<int, int> coins;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        coins[value]++;
    }

    for (int q = 0; q < Q; q++) {
        int value;
        cin >> value;

        int count = 0;

        for (map<int, int>::reverse_iterator it = coins.rbegin(); it != coins.rend(); it++) {
            int use = min(value / it->first, it->second);
            value -= use * it->first;
            count += use;
        }

        cout << (value > 0 ? -1 : count) << '\n';
    }

    return 0;
}