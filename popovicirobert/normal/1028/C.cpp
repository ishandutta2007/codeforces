#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 132674;

pair <int, int> aint[8 * MAXN + 1];

inline void solve_lazy(int nod) {
    if(2 * nod + 1 <= 8 * MAXN) {
        aint[2 * nod].second += aint[nod].second;
        aint[2 * nod + 1].second += aint[nod].second;
    }
    aint[nod].first += aint[nod].second;
    aint[nod].second = 0;
}

void update(int nod, int left, int right, int l, int r, int val) {
    solve_lazy(nod);
    if(l <= left && right <= r) {
        aint[nod].second += val;
        solve_lazy(nod);
    }
    else {
        int mid = (left + right) / 2;
        if(l <= mid)
            update(2 * nod, left, mid, l, r, val);
        if(mid < r)
            update(2 * nod + 1, mid + 1, right, l, r, val);
        solve_lazy(2 * nod);
        solve_lazy(2 * nod + 1);
        aint[nod].first = max(aint[2 * nod].first, aint[2 * nod + 1].first);
    }
}

int get(int nod, int left, int right) {
    solve_lazy(nod);
    if(left == right) {
        return left;
    }
    else {
        int mid = (left + right) / 2;
        solve_lazy(2 * nod);
        solve_lazy(2 * nod + 1);
        if(aint[2 * nod].first == aint[nod].first) {
            return get(2 * nod, left, mid);
        }
        return get(2 * nod + 1, mid + 1, right);
    }
}

struct Rectangle {
    int x1, y1, x2, y2;
}r[MAXN + 1];

vector <int> nrm;
map <int, int> mp;

struct Data {
    int x;
    int y1, y2;
    bool type;
    bool operator <(const Data &other) const {
        return x < other.x;
    }
};

vector <Data> arr;

int vals[2 * MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        nrm.push_back(r[i].y1);
        nrm.push_back(r[i].y2);
        arr.push_back({r[i].x1, r[i].y1, r[i].y2, 0});
        arr.push_back({r[i].x2 + 1, r[i].y1, r[i].y2, 1});
    }
    sort(nrm.begin(), nrm.end());
    int cur = 1;
    for(i = 0; i < nrm.size(); i++) {
        if(i > 0 && nrm[i] != nrm[i - 1]) {
            cur++;
        }
        mp[nrm[i]] = cur;
        vals[cur] = nrm[i];
    }
    sort(arr.begin(), arr.end());
    i = 0;
    while(i < arr.size()) {
        int j = i;
        while(j < arr.size() && arr[i].x == arr[j].x) {
            if(arr[j].type == 0) {
                update(1, 1, cur, mp[arr[j].y1], mp[arr[j].y2], 1);
            }
            else {
                update(1, 1, cur, mp[arr[j].y1], mp[arr[j].y2], -1);
            }
            if(aint[1].first >= n - 1) {
                cout << arr[j].x << " " << vals[get(1, 1, cur)];
                return 0;
            }
            j++;
        }
        i = j;
    }
    //cin.close();
    //cout.close();
    return 0;
}