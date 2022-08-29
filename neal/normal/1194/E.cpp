#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    void reset() {
        memset(&tree[0], 0, tree.size() * sizeof(tree[0]));
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        assert(count <= tree_n);
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }
};


struct segment {
    int16_t a, b1, b2;

    bool operator<(const segment &other) {
        return a < other.a;
    }
};

bool compare_b1(const segment &s, const segment &t) {
    return s.b1 < t.b1;
}

const int C_MAX = 5005;

void compress_coordinates(vector<segment> &vertical, vector<segment> &horizontal) {
    vector<int> vert = {-C_MAX, C_MAX}, horiz = {-C_MAX, C_MAX};

    for (segment &v : vertical)
        vert.push_back(v.a);

    for (segment &h : horizontal)
        horiz.push_back(h.a);

    sort(vert.begin(), vert.end());
    vert.resize(unique(vert.begin(), vert.end()) - vert.begin());
    sort(horiz.begin(), horiz.end());
    horiz.resize(unique(horiz.begin(), horiz.end()) - horiz.begin());

    for (segment &v : vertical) {
        v.a = lower_bound(vert.begin(), vert.end(), v.a) - vert.begin();
        v.b1 = lower_bound(horiz.begin(), horiz.end(), v.b1) - horiz.begin();
        v.b2 = upper_bound(horiz.begin(), horiz.end(), v.b2) - horiz.begin() - 1;
    }

    for (segment &h : horizontal) {
        h.a = lower_bound(horiz.begin(), horiz.end(), h.a) - horiz.begin();
        h.b1 = lower_bound(vert.begin(), vert.end(), h.b1) - vert.begin();
        h.b2 = upper_bound(vert.begin(), vert.end(), h.b2) - vert.begin() - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<segment> vertical, horizontal;

    for (int i = 0; i < N; i++) {
        int16_t x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2)
            swap(x1, x2);

        if (y1 > y2)
            swap(y1, y2);

        if (x1 == x2)
            vertical.push_back({x1, y1, y2});
        else if (y1 == y2)
            horizontal.push_back({y1, x1, x2});
        else
            assert(false);
    }

    compress_coordinates(horizontal, vertical);

    if (vertical.size() > horizontal.size())
        swap(vertical, horizontal);

    sort(vertical.begin(), vertical.end());
    sort(horizontal.begin(), horizontal.end(), compare_b1);
    int V = vertical.size(), H = horizontal.size();
    long long total = 0;
    fenwick_tree<int16_t> tree(H + 2);

    for (int right = 0; right < V; right++) {
        tree.reset();
        int16_t x = vertical[right].a, y_min = vertical[right].b1, y_max = vertical[right].b2;

        for (int left = 0, h = 0; left < right; left++) {
            while (h < H && horizontal[h].b1 <= vertical[left].a) {
                if (horizontal[h].b2 >= x && y_min <= horizontal[h].a && horizontal[h].a <= y_max)
                    tree.update(horizontal[h].a, +1);

                h++;
            }

            int count = tree.query(vertical[left].b1, vertical[left].b2 + 1);
            total += count * (count - 1) / 2;
        }
    }

    cout << total << '\n';
}