#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const long long DENOM = 1000;

struct result {
    long long score;
    int a_count, b_count, either;

    bool operator<(const result &other) const {
        return score < other.score;
    }

    result& operator+=(const result &other) {
        score += other.score;
        a_count += other.a_count;
        b_count += other.b_count;
        either += other.either;
        return *this;
    }
};

int N, A, B;
vector<long long> PA, PB, PAB;

// Returns true if there is some way to split `either` between `a_count` and `b_count` without them exceeding A and B.
bool is_acceptable(const result &res) {
    return res.a_count <= A && res.b_count <= B && res.a_count + res.b_count + res.either <= A + B;
}

// Evaluate the best result where A-pokeballs cost AC and B-pokeballs cost BC.
result evaluate(long long AC, long long BC, bool final = false) {
    result total = {0, 0, 0, 0};

    for (int i = 0; i < N; i++) {
        result choose_neither = {0, 0, 0, 0};
        result choose_a = {PA[i] - AC, 1, 0, 0};
        result choose_b = {PB[i] - BC, 0, 1, 0};
        result choose_both = {PAB[i] - AC - BC, 1, 1, 0};

        // Note: ties in max are broken by choosing the first one.
        result best = max({choose_neither, choose_a, choose_b, choose_both});

        // Check if we could actually use either only A or only B.
        if (best.score > 0 && best.score == choose_a.score && best.score == choose_b.score) {
            best.a_count = best.b_count = 0;
            best.either = 1;
        }

        total += best;
    }

    if (final)
        assert(is_acceptable(total));

    total.score += A * AC + B * BC;
    return total;
}

result b_solve(long long AC, bool final = false) {
    long long low = 0, high = DENOM * DENOM;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (evaluate(AC, mid).b_count <= B)
            high = mid;
        else
            low = mid + 1;
    }

    if (final)
        cerr << "Final b_cost: " << high << endl;

    return evaluate(AC, high, final);
}

result solve() {
    long long low = 0, high = DENOM * DENOM;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (is_acceptable(b_solve(mid)))
            high = mid;
        else
            low = mid + 1;
    }

    cerr << "Final a_cost: " << high << endl;
    return b_solve(high, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(16);

    cin >> N >> A >> B;
    PA.resize(N);
    PB.resize(N);
    PAB.resize(N);

    // Probabilities are all expressed as integers in base DENOM * DENOM.
    for (auto &a : PA) {
        double x;
        cin >> x;
        a = DENOM * round(DENOM * x);
    }

    for (auto &b : PB) {
        double x;
        cin >> x;
        b = DENOM * round(DENOM * x);
    }

    for (int i = 0; i < N; i++)
        PAB[i] = PA[i] + PB[i] - (PA[i] / DENOM) * (PB[i] / DENOM);

    cout << (double) solve().score / (DENOM * DENOM) << '\n';
}