#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    int odd_count = 0;

    for (auto &a : A) {
        cin >> a;
        B.push_back((int) floor(0.5 * a));

        if (a % 2 != 0) {
            B.back() += odd_count % 2 == 0 ? 0 : 1;
            odd_count++;
        }
    }

    for (int i = 0; i < N; i++)
        cout << B[i] << '\n';
}