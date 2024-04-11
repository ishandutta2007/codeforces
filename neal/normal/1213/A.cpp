#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int even = 0, odd = 0;

    while (N-- > 0) {
        int a;
        cin >> a;

        if (a % 2 == 0)
            even++;
        else
            odd++;
    }

    cout << min(even, odd) << '\n';
}