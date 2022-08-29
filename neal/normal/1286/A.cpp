#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
vector<int> P;

int solve(int even, int odd, int before, int after) {
    P[0] = before;
    P[N + 1] = after;

    vector<int> evens, odds;
    int position = 1, mixed = 0;

    while (position <= N) {
        if (P[position] == 0) {
            int end = position;

            while (P[end] == 0)
                end++;

            if ((P[position - 1] + P[end]) % 2 == 0) {
                if (P[end] % 2 == 0)
                    evens.push_back(end - position);
                else
                    odds.push_back(end - position);
            } else {
                mixed++;
            }

            position = end;
        }

        position++;
    }

    sort(evens.rbegin(), evens.rend());
    sort(odds.rbegin(), odds.rend());

    while (!evens.empty() && even >= evens.back()) {
        even -= evens.back();
        evens.pop_back();
    }

    while (!odds.empty() && odd >= odds.back()) {
        odd -= odds.back();
        odds.pop_back();
    }

    return 2 * evens.size() + 2 * odds.size() + mixed;
}

int main() {
    cin >> N;
    P.resize(N + 2);
    vector<bool> present(N + 1, false);

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        present[P[i]] = true;
    }

    int already = 0;

    for (int i = 1; i < N; i++)
        if (P[i] > 0 && P[i + 1] > 0 && (P[i] + P[i + 1]) % 2 != 0)
            already++;

    int even = 0, odd = 0;

    for (int i = 1; i <= N; i++)
        if (!present[i]) {
            if (i % 2 == 0)
                even++;
            else
                odd++;
        }

    int answer = INF;

    for (int before = 1; before <= 2; before++)
        for (int after = 1; after <= 2; after++)
            answer = min(answer, solve(even, odd, before, after));

    answer += already;
    cout << answer << '\n';
}