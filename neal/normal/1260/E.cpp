#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool is_power_of_two(int n) {
    return (n & (n - 1)) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    priority_queue<int, vector<int>, greater<int>> cheapest;
    long long total = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (A[i] < 0)
            break;

        cheapest.push(A[i]);

        if (is_power_of_two(i + 1)) {
            total += cheapest.top();
            cheapest.pop();
        }
    }

    cout << total << '\n';
}