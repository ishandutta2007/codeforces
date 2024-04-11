#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> x(4);

    for (int i = 0; i < 4; i++)
        cin >> x[i];

    sort(x.begin(), x.end());
    cout << x.back() - x[2] << ' ' << x.back() - x[1] << ' ' << x.back() - x[0] << '\n';
}