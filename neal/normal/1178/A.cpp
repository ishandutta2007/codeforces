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
    vector<int> A(N);
    int total = 0;

    for (int &a : A) {
        cin >> a;
        total += a;
    }

    vector<bool> party(N, false);
    int choose = 0, count = 0;

    for (int i = 0; i < N; i++)
        if (i == 0 || A[0] >= 2 * A[i]) {
            party[i] = true;
            choose += A[i];
            count++;
        }

    if (2 * choose > total) {
        cout << count << '\n';

        for (int i = 0; i < N; i++)
            if (party[i]) {
                cout << i + 1;
                count--;
                cout << (count > 0 ? ' ' : '\n');
            }
    } else {
        cout << 0 << '\n';
    }
}