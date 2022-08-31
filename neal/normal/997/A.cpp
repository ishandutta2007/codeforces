#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
long long X, Y;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> X >> Y >> S;
    assert(N == (int) S.size());
    int zeros = 0;

    for (int i = 0; i < N; i++)
        if (S[i] == '0' && (i == 0 || S[i - 1] != '0'))
            zeros++;

    if (zeros == 0) {
        cout << 0 << '\n';
        return 0;
    }

    cout << min(X, Y) * (zeros - 1) + Y << '\n';
    return 0;
}