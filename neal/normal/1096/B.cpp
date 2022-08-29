#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 998244353;

int N;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    long long left = 0, right = 0;

    while (left < N && S[left] == S.front())
        left++;

    while (right < N && S[N - 1 - right] == S.back())
        right++;

    long long total = 0;

    if (S.front() == S.back())
        total = (left + 1) * (right + 1);
    else
        total = left + right + 1;

    printf("%lld\n", total % MOD);
}