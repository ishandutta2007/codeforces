#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long A, B, C, R;
    cin >> A >> B >> C >> R;

    if (A > B)
        swap(A, B);

    long long intersect = min(B, C + R) - max(A, C - R);
    intersect = max(intersect, 0LL);
    cout << B - A - intersect << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}