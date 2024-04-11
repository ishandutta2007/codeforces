#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string WEEK = "abcacba";

long long solve(int start, long long A, long long B, long long C) {
    long long count = 0;
    long long skip = min(A / 3, min(B / 2, C / 2));
    count += 7 * skip;
    A -= 3 * skip;
    B -= 2 * skip;
    C -= 2 * skip;

    for (int i = start; ; i = (i + 1) % 7)
        if (WEEK[i] == 'a') {
            if (A <= 0)
                return count;

            A--;
            count++;
        } else if (WEEK[i] == 'b') {
            if (B <= 0)
                return count;

            B--;
            count++;
        } else if (WEEK[i] == 'c') {
            if (C <= 0)
                return count;

            C--;
            count++;
        } else {
            assert(false);
        }

    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    cin >> A >> B >> C;
    long long best = 0;

    for (int i = 0; i < 7; i++)
        best = max(best, solve(i, A, B, C));

    cout << best << '\n';
}