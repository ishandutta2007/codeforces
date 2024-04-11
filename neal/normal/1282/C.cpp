#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long N, T, A, B;
vector<int> problem_type;
vector<pair<long long, int>> mandatory;
long long easy, hard;

void run_case() {
    cin >> N >> T >> A >> B;
    problem_type.resize(N);
    easy = hard = 0;

    for (int &p : problem_type) {
        cin >> p;

        if (p == 0)
            easy++;
        else
            hard++;
    }

    mandatory.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> mandatory[i].first;
        mandatory[i].second = i;
    }

    if (easy * A + hard * B <= T) {
        cout << N << '\n';
        return;
    }

    sort(mandatory.begin(), mandatory.end());
    long long easy_seen = 0, hard_seen = 0;
    long long accumulated = 0;
    long long best = 0;

    for (int i = 0; i < N; i++) {
        long long time = mandatory[i].first - 1;
        int index = mandatory[i].second;

        if (accumulated <= time) {
            long long count = i;
            long long extra = time - accumulated;

            long long take = min(extra / A, easy - easy_seen);
            count += take;
            extra -= take * A;

            take = min(extra / B, hard - hard_seen);
            count += take;
            extra -= take * B;

            best = max(best, count);
        }

        if (problem_type[index] == 0) {
            accumulated += A;
            easy_seen++;
        } else {
            accumulated += B;
            hard_seen++;
        }
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}