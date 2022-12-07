#include<bits/stdc++.h>

using namespace std;

const int N = 2000030;

int n, q, k, cnt_id;
int a[N];
vector < int > pos[N];

int count_pos(int x, int l, int r) {
    return upper_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l);
}

int left_id[N];
int right_id[N];
vector < vector < int > > to_right[N], to_left[N];

int current_count[N];

int sz;
int in_set[N];
pair < int, int > last[6];

void prepare(int nod, int l, int r) {
    int mid = (l + r) >> 1;
    to_right[nod].resize(r - mid + 1);
    to_left[nod].resize(mid - l + 1);
    sz = 0;
    for(int i = mid; i <= r; ++i) {
        int x = a[i];
        ++current_count[x];
        if(!in_set[x]) {
            for(int i = 0; i < sz; ++i) last[i].first = current_count[last[i].second];
            last[sz++] = make_pair(current_count[x], x);
            sort(last, last + sz);
            if(sz > k) {
                in_set[last[0].second] = 0;
                for(int i = 1; i < sz; ++i) {
                    last[i - 1] = last[i];
                }
                sz--;
            }
            for(int i = 0; i < sz; ++i) {
                in_set[last[i].second] = 1;
            }
        }

        to_right[nod][i - mid].resize(sz);
        for(int j = 0; j < sz; ++j) {
            to_right[nod][i - mid][j] = last[j].second;
        }
    }
    for(int i = mid; i <= r; ++i) {
        int x = a[i];
        in_set[x] = current_count[x] = 0;
    }
    sz = 0;
    for(int i = mid; i >= l; --i) {
        int x = a[i];
        ++current_count[x];
        if(!in_set[x]) {
            for(int i = 0; i < sz; ++i) last[i].first = current_count[last[i].second];
            last[sz++] = make_pair(current_count[x], x);
            sort(last, last + sz);
            if(sz > k) {
                in_set[last[0].second] = 0;
                for(int i = 1; i < sz; ++i) {
                    last[i - 1] = last[i];
                }
                sz--;
            }
            for(int i = 0; i < sz; ++i) {
                in_set[last[i].second] = 1;
            }
        }

        to_left[nod][mid - i].resize(sz);
        for(int j = 0; j < sz; ++j) {
            to_left[nod][mid - i][j] = last[j].second;
        }
    }
    for(int i = mid; i >= l; --i) {
        int x = a[i];
        in_set[x] = current_count[x] = 0;
    }
    if(l < mid) {
        prepare(left_id[nod] = ++cnt_id, l, mid - 1);
    }
    if(r > mid) {
        prepare(right_id[nod] = ++cnt_id, mid + 1, r);
    }
}

vector < int > cand;

void query(int nod, int l, int r, int u, int v) {
    if(l > v || r < u) return;
    int mid = (l + r) >> 1;
    if(u <= mid && v >= mid) {
        for(int x : to_left[nod][mid - u]) cand.push_back(x);
        for(int x : to_right[nod][v - mid]) cand.push_back(x);
        return;
    }

    if(l < mid) query(left_id[nod], l, mid - 1, u, v);
    if(r > mid) query(right_id[nod], mid + 1, r, u, v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]].push_back(i);

    k = 5;
    prepare(0, 1, n);

    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        query(0, 1, n, l, r);
        int ans = n + 1;
        for(int x : cand) {
            if(count_pos(x, l, r) * k > (r - l + 1)) ans = min(ans, x);
        }
        cand.clear();
        cout << (ans <= n ? ans : -1) << "\n";
    }

    return 0;
}