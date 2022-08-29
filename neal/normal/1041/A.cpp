#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> keyboards(n);

    for (int i = 0; i < n; i++)
        cin >> keyboards[i];

    int most = *max_element(keyboards.begin(), keyboards.end());
    int least = *min_element(keyboards.begin(), keyboards.end());
    cout << most - least + 1 - n << '\n';
}