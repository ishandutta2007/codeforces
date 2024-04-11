#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N;
    string students;
    cin >> N >> students;
    int most = 0;
    int closest_A = -1;

    for (int i = 0; i < N; i++)
        if (students[i] == 'A')
            closest_A = i;
        else if (closest_A >= 0)
            most = max(most, i - closest_A);

    cout << most << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}