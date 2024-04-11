#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, bool maximum_mode>
struct monotonic_rmq {
    vector<pair<T, int>> values;
    int front = 0, current_index = 0;

    int size() const {
        return (int) values.size() - front;
    }

    bool better(const T &a, const T &b) const {
        return (a < b) ^ maximum_mode;
    }

    // Adds a value and returns its index.
    int add(const T &x) {
        while (size() > 0 && !better(values.back().first, x))
            values.pop_back();

        values.emplace_back(x, current_index);
        return current_index++;
    }

    // Queries for the maximum (minimum) with index at least the given `index`.
    T query(int index) {
        while (size() > 0 && values[front].second < index)
            front++;

        assert(size() > 0);
        return values[front].first;
    }
};


const int INF = 1e9 + 5;

int N, W;
vector<long long> values, changes;

void add_single(int index, int change) {
    values[index] += change;
}

void add_range(int start, int end, int change) {
    changes[start] += change;
    changes[end] -= change;
}

void process(vector<int> &A) {
    int L = A.size();

    if (W >= 2 * L) {
        vector<int> prefix_max(L + 1, 0);
        vector<int> suffix_max(L + 1, 0);

        for (int i = 0; i < L; i++)
            prefix_max[i + 1] = max(prefix_max[i], A[i]);

        for (int i = L - 1; i >= 0; i--)
            suffix_max[i] = max(suffix_max[i + 1], A[i]);

        for (int i = 0; i < L; i++) {
            add_single(i, prefix_max[i + 1]);
            add_single(W - L + i, suffix_max[i]);
        }

        add_range(L, W - L, prefix_max[L]);
    } else {
        monotonic_rmq<int, true> rmq;
        int start = 0;

        for (int i = 0; i < W; i++) {
            if (i < L)
                rmq.add(A[i]);

            int current = rmq.query(start);

            if (i < W - L || i >= L)
                current = max(current, 0);

            add_single(i, current);

            if (i >= W - L)
                start++;
        }
    }
}

void play_events() {
    long long sum = 0;

    for (int i = 0; i < W; i++) {
        sum += changes[i];
        values[i] += sum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;
    values.assign(W, 0);
    changes.assign(W + 1, 0);

    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        vector<int> A(L);

        for (int &a : A)
            cin >> a;

        process(A);
    }

    play_events();

    for (int i = 0; i < W; i++)
        cout << values[i] << (i < W - 1 ? ' ' : '\n');
}