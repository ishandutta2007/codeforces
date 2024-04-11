#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> output;

    int top = 1, bottom = N;

    while (top < bottom) {
        for (int i = 1; i <= M; i++) {
            output.emplace_back(top, i);
            output.emplace_back(bottom, M + 1 - i);
        }

        top++;
        bottom--;
    }

    if (top == bottom) {
        int left = 1, right = M;

        while (left < right) {
            output.emplace_back(top, left);
            output.emplace_back(top, right);
            left++;
            right--;
        }

        if (left == right)
            output.emplace_back(top, left);
    }

    for (auto &p : output)
        cout << p.first << ' ' << p.second << '\n';
}