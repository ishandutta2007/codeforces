#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

pair <int, int> a[MAXN + 1];
int aint[4 * MAXN + 1];

void build(int nod, int left, int right) {
    if(left == right) {
        aint[nod] = left;
    }
    else {
        int mid = (left + right) / 2;
        build(2 * nod, left, mid);
        build(2 * nod + 1, mid + 1, right);
        if(a[aint[2 * nod]].second < a[aint[2 * nod + 1]].second) {
            aint[nod] = aint[2 * nod];
        }
        else {
            aint[nod] = aint[2 * nod + 1];
        }
    }
}

void update(int nod, int left, int right, int pos) {
    if(left == right) {
        aint[nod] = 0;
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid) {
            update(2 * nod, left, mid, pos);
        }
        else {
            update(2 * nod + 1, mid + 1, right, pos);
        }
        if(a[aint[2 * nod]].second < a[aint[2 * nod + 1]].second) {
            aint[nod] = aint[2 * nod];
        }
        else {
            aint[nod] = aint[2 * nod + 1];
        }
    }
}

void query(int nod, int left, int right, int l, int r, int &mn, int &pos) {
    if(l <= left && right <= r) {
        if(mn > a[aint[nod]].second) {
            mn = a[aint[nod]].second;
            pos = aint[nod];
        }
    }
    else {
        int mid = (left + right) / 2;
        if(l <= mid)
            query(2 * nod, left, mid, l, r, mn, pos);
        if(mid < r)
            query(2 * nod + 1, mid + 1, right, l, r, mn, pos);
    }
}


int cur[MAXN + 1], n;
int sol[MAXN + 1];

void solve(int l, int r, int par) {
    if(l > r) {
        return ;
    }
    if(l == r) {
        cur[l] = par;
        return ;
    }
    int mn = MAXN + 1, mid;
    query(1, 1, n, l, r, mn, mid);
    //cerr << l << " " << r << " " << mid << "\n";
    cur[mid] = par;
    update(1, 1, n, mid);
    solve(l, mid - 1, mid);
    solve(mid + 1, r, mid);
}

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    /*for(i = 1; i <= n; i++) {
        cerr << a[i].first << " " << a[i].second << "\n";
    }
    cerr << "\n";*/
    a[0] = {MAXN + 1, MAXN + 1};
    build(1, 1, n);
    solve(1, n, 0);
    for(i = 1; i <= n; i++) {
        sol[a[i].second] = a[cur[i]].first;
    }
    for(i = 2; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}