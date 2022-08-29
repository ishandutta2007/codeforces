#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0) {
        int N;
        string S;
        cin >> N >> S;

        if (N == 2 && S[0] >= S[1]) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            cout << 2 << '\n';
            cout << S[0] << ' ' << S.substr(1) << '\n';
        }
    }
}