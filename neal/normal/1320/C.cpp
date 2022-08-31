#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const long long LL_INF = (long long) 2e18 + 5;

struct segment_change {
    long long to_add;

    segment_change(long long _to_add = 0) : to_add(_to_add) {}
};

struct segment {
    long long max_prefix, sum;

    segment(long long _max_prefix = -LL_INF, long long _sum = 0) : max_prefix(_max_prefix), sum(_sum) {}

    void apply(const segment_change &change) {
        max_prefix += change.to_add;
        sum += change.to_add;
    }

    void join(const segment &other) {
        max_prefix = max(max_prefix, sum + other.max_prefix);
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct max_prefix_sum_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    max_prefix_sum_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = initial.size();
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment_change &change) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position].apply(change);
        join_up(position);
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};

struct add_max_seg_tree {
    // Build a `max_prefix_sum_tree` on the consecutive differences of the array.
    max_prefix_sum_tree tree;

    add_max_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree.init(n);
    }

    void build(const vector<long long> &initial) {
        vector<segment> segment_initial(initial.size());
        long long previous = 0;

        for (int i = 0; i < (int) initial.size(); i++) {
            long long value = initial[i] - previous;
            previous = initial[i];
            segment_initial[i] = segment(value, value);
        }

        tree.build(segment_initial);
    }

    long long query(int a, int b) const {
        return tree.query(0, a).sum + tree.query(a, b).max_prefix;
    }

    long long query_full() const {
        return tree.tree[1].max_prefix;
    }

    void update(int a, int b, segment_change change) {
        if (a < tree.tree_n)
            tree.update(a, change);

        if (b < tree.tree_n) {
            change.to_add *= -1;
            tree.update(b, change);
        }
    }

    void set_value(int index, long long value) {
        long long current = query(index, index + 1);
        update(index, index + 1, segment_change(value - current));
    }
};


struct tool {
    int value, cost;

    bool operator<(const tool &other) const {
        return value < other.value;
    }
};

struct monster {
    int x, y, coins;

    bool operator<(const monster &other) const {
        return x < other.x;
    }
};

int N, M, P;
vector<tool> weapons, armors;
vector<monster> monsters;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> P;
    weapons.resize(N);
    armors.resize(M);
    monsters.resize(P);

    for (tool &weapon : weapons)
        cin >> weapon.value >> weapon.cost;

    for (tool &armor : armors)
        cin >> armor.value >> armor.cost;

    for (monster &mon : monsters)
        cin >> mon.x >> mon.y >> mon.coins;

    sort(weapons.begin(), weapons.end());
    sort(armors.begin(), armors.end());
    sort(monsters.begin(), monsters.end());
    add_max_seg_tree tree(M);
    vector<long long> initial(M);

    for (int i = 0; i < M; i++)
        initial[i] = -armors[i].cost;

    tree.build(initial);
    long long best = -LL_INF;

    for (int i = 0, mon = 0; i < N; i++) {
        int x = weapons[i].value;

        while (mon < P && monsters[mon].x < x) {
            int y = monsters[mon].y;
            tool t;
            t.value = y;
            int index = upper_bound(armors.begin(), armors.end(), t) - armors.begin();
            tree.update(index, M, segment_change(monsters[mon].coins));
            mon++;
        }

        best = max(best, -weapons[i].cost + tree.query_full());
    }

    cout << best << '\n';
}