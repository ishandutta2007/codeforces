#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const long long INF = 1LL << 62;

struct Work {
    int64_t L, R, t;
} a[N];
int n;

set< pair<int64_t, int > > first; // <t_i, i>
set< pair<int64_t, int > > second; // <L_i + t_i, i>

vector< pair<int64_t, int> > Left; // <L_i, i> | sorted increasingly
vector< pair<int64_t, int> > Right; // <R_i - t_i, i> | sorted decreasingly

int cur_left_pos;

void try_erase(set< pair<int64_t, int> > &S, pair<int64_t, int> e) {
    auto it = S.find(e);
    if (it != S.end()) S.erase(it);
}

void try_pop(int64_t x) {
    while (!Right.empty() && Right.back().first < x) {
        int i = Right.back().second;
        //cerr << "try_erase " << i << endl;
        try_erase(first, {a[i].t, i});
        try_erase(second, {a[i].L + a[i].t, i});
        Right.pop_back();
    }
}

void balance(int64_t x) {
    while (cur_left_pos < n && Left[cur_left_pos].first <= x) {
        int i = Left[cur_left_pos].second;
        first.insert({a[i].t, i});
        try_erase(second, {a[i].L + a[i].t, i});
        cur_left_pos++;
    }
}

int64_t get(int64_t x) {
    balance(x);
    try_pop(x);
    int64_t res = INF;
    if (first.size()) {
        res = min(res, x + first.begin()->first);
    }
    if (second.size()) {
        res = min(res, second.begin()->first);
    }
    return res;
}

void gen() {
    n = 2e5;
    const int64_t limit = 1000000000000000000LL;
    for (int i = 0; i < n; ++i) {
        a[i].L = rand() % limit + 1;
        a[i].R = rand() % limit + 1;
        if (a[i].L > a[i].R) swap(a[i].L, a[i].R);
        a[i].t = rand() % (a[i].R - a[i].L) + 1;
        assert(a[i].L + a[i].t <= a[i].R);
    }
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].L >> a[i].R >> a[i].t;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //gen();
    read();

    for (int i = 0; i < n; ++i) {
        Left.push_back({a[i].L, i});
        Right.push_back({a[i].R - a[i].t, i});
    }
    sort(begin(Left), end(Left));
    sort(rbegin(Right), rend(Right));

    vector<int64_t> events;
    for (int i = 0; i < n; ++i) {
        events.push_back(a[i].L);
        events.push_back(a[i].R);
    }
    sort(begin(events), end(events));

    for (int i = 0; i < n; ++i) {
        second.insert({a[i].L + a[i].t, i});
    }

    int64_t x = 0;
    int64_t res = 0;
    int event_pos = 0;
    while (true) {
        int64_t to = get(x);
        //cerr << res << ' ' << to << ' ' << first.size() << ' ' << second.size() << endl;
        if (to == INF) break;
        res += 1; // one jump

        // multiple jumps
        if (events[event_pos] >= to) {
            int64_t to2 = get(to);
            int64_t step = to2 - to;
            //assert(event_pos < events.size());
            int64_t more = (events[event_pos] - to) / step;
            res += more;

            x = to + more * step;
        } else {
            x = to;
        }
        event_pos++;
    }

    cout << res << endl;

    return 0;
}