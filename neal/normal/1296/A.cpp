#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N;
    cin >> N;
    int odd = 0, even = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a % 2 == 0)
            even++;
        else
            odd++;
    }

    bool answer = (odd > 0 && even > 0) || (odd > 0 && N % 2 != 0);
    cout << (answer ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}