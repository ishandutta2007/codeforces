#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H;
    cin >> W >> H;
    long long answer = 1;

    for (int i = 0; i < W + H; i++)
        answer = 2 * answer % MOD;

    cout << answer << '\n';
}