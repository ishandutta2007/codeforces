#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> bills) {
    int count = 0;

    for (int bill : bills) {
        count += n / bill;
        n %= bill;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cout << solve(N, vector<int>({100, 20, 10, 5, 1})) << '\n';
    return 0;
}