#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> tabs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    tabs.resize(N);

    for (int i = 0; i < N; i++)
        cin >> tabs[i];

    int most = 0;

    for (int b = 0; b < N; b++) {
        int sum = 0;

        for (int i = 0; i < N; i++)
            if (i % K != b % K)
                sum += tabs[i];

        most = max(most, abs(sum));
    }

    cout << most << '\n';
}