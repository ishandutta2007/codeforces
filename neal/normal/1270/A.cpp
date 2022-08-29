#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N, K[2];
    cin >> N >> K[0] >> K[1];
    int biggest = -1, bigger = -1;

    for (int k = 0; k < 2; k++)
        for (int i = 0; i < K[k]; i++) {
            int a;
            cin >> a;

            if (a > biggest) {
                biggest = a;
                bigger = k;
            }
        }

    cout << (bigger == 0 ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}