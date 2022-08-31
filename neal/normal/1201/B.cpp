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
    vector<long long> A(N);
    long long sum = 0, big = 0;

    for (long long &a : A) {
        cin >> a;
        sum += a;
        big = max(big, a);
    }

    cout << (sum % 2 == 0 && big <= sum / 2 ? "YES" : "NO") << '\n';
}