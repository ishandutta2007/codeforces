#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
int main() {
    int n;
    cin >> n;
    vector<int> years(n);

    for (int i = 0; i < n; ++i) {
        cin >> years[i];
    }

    sort(years.begin(), years.end());
    cout << years[n / 2] << '\n';

    return 0;
}
#pragma clang diagnostic pop