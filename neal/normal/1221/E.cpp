#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const string YES = "YES", NO = "NO";

void solve_case() {
    int A, B;
    string S;
    cin >> A >> B >> S;

    vector<int> groups;
    int count = 0;

    for (char c : S)
        if (c == '.') {
            count++;
        } else if (count > 0) {
            groups.push_back(count);
            count = 0;
        }

    if (count > 0)
        groups.push_back(count);

    for (int g : groups)
        if (B <= g && g < A) {
            cout << NO << '\n';
            return;
        }

    int between = 0, above = 0;

    for (int g : groups)
        if (A <= g && g < 2 * B)
            between++;
        else if (g >= 2 * B)
            above++;

    if (above >= 2) {
        cout << NO << '\n';
        return;
    }

    if (above == 0) {
        cout << (between % 2 == 0 ? NO : YES) << '\n';
        return;
    }

    int biggest = *max_element(groups.begin(), groups.end());
    bool alice = false;

    for (int split = 0; split <= biggest - A; split++) {
        int remaining = biggest - A - split;

        if ((B <= split && split < A) || (B <= remaining && remaining < A))
            continue;

        if (split >= 2 * B || remaining >= 2 * B)
            continue;

        int add = (A <= split && split < 2 * B) + (A <= remaining && remaining < 2 * B);

        if ((between + add) % 2 == 0)
            alice = true;
    }

    cout << (alice ? YES : NO) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}