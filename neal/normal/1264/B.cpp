#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int A, B, C, D;

void fail() {
    cout << "NO" << '\n';
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C >> D;

    if (2 * max({A, B, C, D}) > A + B + C + D + 1)
        fail();

    if (A - B > 1 || D - C > 1)
        fail();

    if (A - B == 1) {
        if (C + D > 0)
            fail();

        cout << "YES" << '\n';

        for (int i = 0; i < B; i++)
            cout << 0 << ' ' << 1 << ' ';

        cout << 0 << '\n';
        return 0;
    }

    if (D - C == 1) {
        if (A + B > 0)
            fail();

        cout << "YES" << '\n';

        for (int i = 0; i < C; i++)
            cout << 3 << ' ' << 2 << ' ';

        cout << 3 << '\n';
        return 0;
    }

    // Can assume A <= B and C >= D
    assert(A <= B && C >= D);

    if (abs((B - A) - (C - D)) > 1)
        fail();

    vector<int> output;
    vector<int> rev_output;

    if (B - A > C - D) {
        output.push_back(1);
        B--;
    }

    if (C - D > B - A) {
        rev_output.push_back(2);
        C--;
    }

    assert(B - A == C - D);

    while (A > 0) {
        output.push_back(0);
        output.push_back(1);
        A--; B--;
    }

    while (D > 0) {
        rev_output.push_back(3);
        rev_output.push_back(2);
        C--; D--;
    }

    assert(B == C);

    for (int i = 0; i < B; i++) {
        output.push_back(2);
        output.push_back(1);
    }

    while (!rev_output.empty()) {
        output.push_back(rev_output.back());
        rev_output.pop_back();
    }

    cout << "YES" << '\n';
    int n = output.size();

    for (int i = 0; i < n; i++)
        cout << output[i] << (i < n - 1 ? ' ' : '\n');
}