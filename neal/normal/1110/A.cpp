#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int B, K;
    cin >> B >> K;
    long long sum = 0;

    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        sum += a * (i == K - 1 ? 1 : B % 2);
    }

    cout << (sum % 2 == 0 ? "even" : "odd") << '\n';
}