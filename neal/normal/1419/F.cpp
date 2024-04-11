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

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


// Warning: be careful with this constant (don't do INF + INF).
const int INF = 2e9 + 5;

int N;
vector<array<int, 2>> XY, YX;
vector<int> YX_to_XY;
vector<array<int, 3>> edges;

pair<int, int> get_neighbor(int x, int y, int dir) {
    if (dir < 2) {
        int index = int(lower_bound(XY.begin(), XY.end(), array<int, 2>{x, y}) - XY.begin());
        index -= dir == 0;

        if (0 <= index && index < N && XY[index][0] == x)
            return {index, abs(XY[index][1] - y)};

        return {-1, INF};
    } else {
        int index = int(lower_bound(YX.begin(), YX.end(), array<int, 2>{y, x}) - YX.begin());
        index -= dir == 2;

        if (0 <= index && index < N && YX[index][0] == y)
            return {YX_to_XY[index], abs(YX[index][1] - x)};

        return {-1, INF};
    }
}

bool possible(int T) {
    union_find UF(N);

    for (auto &e : edges)
        if (e[0] <= T)
            UF.unite(e[1], e[2]);

    if (UF.components <= 1)
        return true;

    if (UF.components > 4)
        return false;

    vector<int> roots;

    for (int i = 0; i < N; i++)
        if (UF.find(i) == i)
            roots.push_back(i);

    int R = int(roots.size());

    auto which_root = [&](int root) {
        for (int i = 0; i < R; i++)
            if (roots[i] == root)
                return i;

        assert(false);
    };

    auto test_point = [&](int x, int y) {
        vector<bool> seen(R, false);
        int seen_count = 0;

        for (int dir = 0; dir < 4; dir++) {
            pair<int, int> neigh = get_neighbor(x, y, dir);

            if (neigh.second <= T) {
                int r = which_root(UF.find(neigh.first));
                seen_count += !seen[r];
                seen[r] = true;

                if (seen_count == R)
                    return true;
            }
        }

        return false;
    };

    for (int i = 0; i < N - 1; i++) {
        if (XY[i][0] == XY[i + 1][0]) {
            int x = XY[i][0];
            int y = (XY[i][1] + XY[i + 1][1]) / 2;

            if (test_point(x, y))
                return true;
        }

        if (YX[i][0] == YX[i + 1][0]) {
            int y = YX[i][0];
            int x = (YX[i][1] + YX[i + 1][1]) / 2;

            if (test_point(x, y))
                return true;
        }
    }

    vector<int> x_mask(N, 0), y_mask(N, 0);

    auto compress_x = [&](int x) {
        return int(lower_bound(XY.begin(), XY.end(), array<int, 2>{x, -INF}) - XY.begin());
    };

    auto compress_y = [&](int y) {
        return int(lower_bound(YX.begin(), YX.end(), array<int, 2>{y, -INF}) - YX.begin());
    };

    for (int i = 0; i < N; i++) {
        x_mask[compress_x(XY[i][0])] |= 1 << which_root(UF.find(i));
        y_mask[compress_y(XY[i][1])] |= 1 << which_root(UF.find(i));
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if ((x_mask[i] | y_mask[j]) == (1 << R) - 1)
                if (test_point(XY[i][0], YX[j][0]))
                    return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        XY.push_back({x, y});
        YX.push_back({y, x});
    }

    sort(XY.begin(), XY.end());
    sort(YX.begin(), YX.end());
    YX_to_XY.assign(N, -1);

    for (int i = 0; i < N; i++)
        YX_to_XY[i] = int(lower_bound(XY.begin(), XY.end(), array<int, 2>{YX[i][1], YX[i][0]}) - XY.begin());

    for (int i = 0; i < N; i++)
        for (int dir = 0; dir < 4; dir++) {
            pair<int, int> neigh = get_neighbor(XY[i][0], XY[i][1], dir);

            if (neigh.first >= 0 && neigh.first != i)
                edges.push_back({neigh.second, i, neigh.first});
        }

    sort(edges.begin(), edges.end());
    int64_t low = 0, high = INF;

    while (low < high) {
        int64_t mid = (low + high) / 2;

        if (possible(int(mid)))
            high = mid;
        else
            low = mid + 1;
    }

    cout << (low < INF ? low : -1) << '\n';
}