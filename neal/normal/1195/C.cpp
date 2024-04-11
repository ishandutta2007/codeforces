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
    vector<int> first(N), second(N);

    for (int &h : first)
        cin >> h;

    for (int &h : second)
        cin >> h;

    long long best_first = 0, best_second = 0;

    for (int i = 0; i < N; i++) {
        long long new_best_first = first[i] + best_second;
        long long new_best_second = second[i] + best_first;
        best_first = max(best_first, new_best_first);
        best_second = max(best_second, new_best_second);
    }

    cout << max(best_first, best_second) << '\n';
}