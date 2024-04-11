#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, L, R;
    cin >> N >> L >> R;
    long long minimum = (1 << L) - 1 + (N - L);
    long long maximum = (1 << R) - 1 + (N - R) * (1 << (R - 1));
    cout << minimum << ' ' << maximum << '\n';
}