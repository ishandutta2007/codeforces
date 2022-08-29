#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    string P, H;
    cin >> P >> H;
    int N = P.size();
    sort(P.begin(), P.end());

    for (int i = 0; i + N <= (int) H.size(); i++) {
        string HS = H.substr(i, N);
        sort(HS.begin(), HS.end());

        if (P == HS) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}