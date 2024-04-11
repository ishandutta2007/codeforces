#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int INF = 1e9 + 5;

struct segment_change {
    int to_add;

    segment_change(int _to_add = 0) : to_add(_to_add) {}

    void reset() {
        to_add = 0;
    }

    bool has_change() const {
        return to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    int minimum, count_of_min;

    segment(int _minimum = INF, int _count_of_min = 0) : minimum(_minimum), count_of_min(_count_of_min) {}

    void apply(int, const segment_change &change) {
        minimum += change.to_add;
    }

    void join(const segment &other) {
        if (other.minimum < minimum)
            *this = other;
        else if (other.minimum == minimum)
            count_of_min += other.count_of_min;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }

    int get_goal_count(int goal) const {
        return minimum == goal ? count_of_min : 0;
    }
};

pair<int, int> right_half[32];

struct min_count_seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    min_count_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void push_down(int position, int length) {
        if (!changes[position].has_change())
            return;

        if (2 * position < tree_n) {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);

            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};


struct rectangle {
    int x1, y1, x2, y2;
};

struct rect_event {
    int x, y1, y2, change;

    bool operator<(const rect_event &other) const {
        return x < other.x;
    }
};

int64_t rectangle_union_area(const vector<rectangle> &rects) {
    if (rects.empty())
        return 0;

    vector<int> Xs, Ys;
    vector<rect_event> events;

    for (const rectangle &rect : rects) {
        Xs.push_back(rect.x1);
        Xs.push_back(rect.x2);
        Ys.push_back(rect.y1);
        Ys.push_back(rect.y2);
        events.push_back({rect.x1, rect.y1, rect.y2, +1});
        events.push_back({rect.x2, rect.y1, rect.y2, -1});
    }

    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    Xs.resize(unique(Xs.begin(), Xs.end()) - Xs.begin());
    Ys.resize(unique(Ys.begin(), Ys.end()) - Ys.begin());
    int XC = int(Xs.size());
    int YC = int(Ys.size());
    int Y_range = Ys.back() - Ys.front();

    sort(events.begin(), events.end());
    int E = int(events.size());

    auto &&compress_y = [&](int y) {
        return int(lower_bound(Ys.begin(), Ys.end(), y) - Ys.begin());
    };

    min_count_seg_tree tree(YC - 1);
    vector<segment> initial(YC - 1);

    for (int i = 0; i < YC - 1; i++)
        initial[i] = segment(0, Ys[i + 1] - Ys[i]);

    tree.build(initial);
    int64_t area = 0;

    for (int i = 0, e = 0; i < XC - 1; i++) {
        while (e < E && events[e].x <= Xs[i]) {
            int y1 = compress_y(events[e].y1);
            int y2 = compress_y(events[e].y2);
            tree.update(y1, y2, segment_change(events[e].change));
            e++;
        }

        segment result = tree.tree[1];
        area += int64_t(Y_range - result.get_goal_count(0)) * (Xs[i + 1] - Xs[i]);
    }

    return area;
}


int N, M, NM;
vector<string> grid;
vector<int> slides_to;
vector<vector<int>> adj;
vector<int> tour_start, tour_end;
int tour;

bool valid(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < M;
}

int key(int r, int c) {
    return valid(r, c) ? r * M + c : -1;
};

void dfs(int node, int parent) {
    tour_start[node] = tour++;

    for (int neigh : adj[node])
        if (neigh != parent)
            dfs(neigh, node);

    tour_end[node] = tour;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;
    NM = N * M;
    grid.resize(N);

    for (string &row : grid)
        cin >> row;

    slides_to.assign(NM, -1);

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            int me = key(r, c);

            switch (grid[r][c]) {
                case 'L': slides_to[me] = key(r, c + 2); break;
                case 'R': slides_to[me] = key(r, c - 2); break;
                case 'U': slides_to[me] = key(r + 2, c); break;
                case 'D': slides_to[me] = key(r - 2, c); break;
            }
        }

    adj.assign(NM, {});

    for (int i = 0; i < NM; i++)
        if (slides_to[i] >= 0)
            adj[slides_to[i]].push_back(i);

    tour_start.assign(NM, -1);
    tour_end.assign(NM, -1);
    tour = 0;

    for (int i = 0; i < NM; i++)
        if (slides_to[i] < 0)
            dfs(i, -1);

    vector<rectangle> rects;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == 'L' || grid[r][c] == 'U') {
                int key0 = key(r, c);
                int key1 = grid[r][c] == 'L' ? key(r, c + 1) : key(r + 1, c);

                if ((r + c) % 2 != 0)
                    swap(key0, key1);

                rects.push_back({tour_start[key0], tour_start[key1], tour_end[key0], tour_end[key1]});
            }

    cout << rectangle_union_area(rects) << '\n';
}