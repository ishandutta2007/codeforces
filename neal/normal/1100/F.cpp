#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Complexity: log^2

const int BITS = 20;

template<typename T>
struct xor_basis {
    // A list of basis values sorted in decreasing order, where each value has a unique highest bit.
    // We use a static array instead of a vector for better performance.
    T basis[BITS];
    int n = 0;

    T min_value(T start) const {
        if (n == BITS)
            return 0;

        for (int i = 0; i < n; i++)
            start = min(start, start ^ basis[i]);

        return start;
    }

    T max_value(T start = 0) const {
        if (n == BITS)
            return ((T) 1 << BITS) - 1;

        for (int i = 0; i < n; i++)
            start = max(start, start ^ basis[i]);

        return start;
    }

    bool add(T x) {
        x = min_value(x);

        if (x == 0)
            return false;

        basis[n++] = x;

        // Insertion sort.
        for (int k = n - 1; k > 0 && basis[k] > basis[k - 1]; k--)
            swap(basis[k], basis[k - 1]);

        return true;
    }

    void merge(const xor_basis<T> &other) {
        for (int i = 0; i < other.n && n < BITS; i++)
            add(other.basis[i]);
    }

    void merge(const xor_basis<T> &a, const xor_basis<T> &b) {
        if (a.n > b.n) {
            *this = a;
            merge(b);
        } else {
            *this = b;
            merge(a);
        }
    }
};


struct query {
    int L, R, index;
};

int N, Q;
vector<int> burgers;
vector<int> answers;
vector<xor_basis<int>> solutions;

void solve(int start, int end, const vector<query> &queries) {
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    solutions[mid].n = 0;

    for (int i = mid - 1; i >= start; i--) {
        solutions[i] = solutions[i + 1];
        solutions[i].add(burgers[i]);
    }

    for (int i = mid; i < end; i++) {
        solutions[i + 1] = solutions[i];
        solutions[i + 1].add(burgers[i]);
    }

    vector<query> left_queries, right_queries;
    xor_basis<int> sol;

    for (const query &q : queries)
        if (q.R < mid) {
            left_queries.push_back(q);
        } else if (q.L > mid) {
            right_queries.push_back(q);
        } else {
            sol.merge(solutions[q.L], solutions[q.R]);
            answers[q.index] = sol.max_value();
        }

    solve(start, mid - 1, left_queries);
    solve(mid + 1, end, right_queries);
}

int main() {
    scanf("%d", &N);
    burgers.resize(N);
    solutions.resize(N + 1);

    for (int &burger : burgers)
        scanf("%d", &burger);

    scanf("%d", &Q);
    vector<query> queries(Q);
    answers.resize(Q);

    for (int q = 0; q < Q; q++) {
        scanf("%d %d", &queries[q].L, &queries[q].R);
        queries[q].L--;
        queries[q].index = q;
    }

    solve(0, N, queries);

    for (int q = 0; q < Q; q++)
        printf("%d\n", answers[q]);
}