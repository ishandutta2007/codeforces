#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = 1e9;
const int MAXN = (int) 1e5;

struct Bus {
    int l, r, t;
    int pos;
    bool operator <(const Bus &other) const {
        return l < other.l;
    }
}bus[MAXN + 1], arr[MAXN + 1];

struct Aint {
    Aint *st, *dr;
    int mx, id;
    Aint() {
        st = dr = NULL;
        mx = 0;
    }
};

Aint *root = new Aint;

void update(Aint *nod, int left, int right, int pos, int val, int id) {
    if(left == right) {
        if(nod -> mx < val) {
            nod -> mx = val;
            nod -> id = id;
        }
        //cerr << left << " " << right << "\n";
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid) {
            if(nod -> st == NULL) {
                nod -> st = new Aint;
            }
            update(nod -> st, left, mid, pos, val, id);
        }
        else {
            if(nod -> dr == NULL) {
                nod -> dr = new Aint;
            }
            update(nod -> dr, mid + 1, right, pos, val, id);
        }
        if(nod -> st != NULL && nod -> st -> mx > nod -> mx) {
            nod -> mx = nod -> st -> mx;
            nod -> id = nod -> st -> id;
        }
        if(nod -> dr != NULL && nod -> dr -> mx > nod -> mx) {
            nod -> mx = nod -> dr -> mx;
            nod -> id = nod -> dr -> id;
        }
    }
}

int sol[MAXN + 1];

pair <int, int> query(Aint *nod, int left, int right, int r, int pos) {
    if(nod == NULL) {
        return {-1, -1};
    }
    if(left >= pos) {
        if(left == right) {
            return {nod -> mx, nod -> id};
        }
        int mid = (left + right) / 2;
        if(nod -> st != NULL && nod -> st -> mx >= r) {
            return query(nod -> st, left, mid, r, pos);
        }
        else {
            return query(nod -> dr, mid + 1, right, r, pos);
        }
    }
    else {
        int mid = (left + right) / 2;
        pair <int, int> ans = {-1, -1};
        if(pos <= mid) {
            ans = query(nod -> st, left, mid, r, pos);
        }
        if(ans.first < r) {
            ans = query(nod -> dr, mid + 1, right, r, pos);
        }
        if(ans.first < r) {
            ans = {-1, -1};
        }
        return ans;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> bus[i].l >> bus[i].r >> bus[i].t;
        bus[i].pos = i;
    }
    sort(bus + 1, bus + n + 1);
    for(i = 1; i <= m; i++) {
        cin >> arr[i].l >> arr[i].r >> arr[i].t;
        arr[i].pos = i;
    }
    sort(arr + 1, arr + m + 1);
    int pos = 1;
    for(i = 1; i <= m; i++) {
        while(pos <= n && bus[pos].l <= arr[i].l) {
            update(root, 0, INF, bus[pos].t, bus[pos].r, bus[pos].pos);
            pos++;
        }
        sol[arr[i].pos] = query(root, 0, INF, arr[i].r, arr[i].t).second;
    }
    for(i = 1; i <= m; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}