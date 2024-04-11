#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> numbers(N);
    vector<int> prefix_count(N + 1, 0);
    set<int> seen;

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        prefix_count[i + 1] = prefix_count[i] + (seen.insert(numbers[i]).second ? 1 : 0);
    }

    long long total = 0;
    seen.clear();

    for (int i = N - 1; i >= 0; i--)
        if (seen.insert(numbers[i]).second)
            total += prefix_count[i];

    cout << total << '\n';
    return 0;
}