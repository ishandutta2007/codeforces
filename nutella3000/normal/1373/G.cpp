#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 7e5;

int n, k;

int Max[4 * max_n], lazy[4 * max_n];

void upd(int v, int x) {
    Max[v] += x;
    lazy[v] += x;
} 

void push(int v) {
    upd(v * 2, lazy[v]);
    upd(v * 2 + 1, lazy[v]);
    lazy[v] = 0;
}

void upd(int v, int l, int r, int left, int right, int x) {
    if (l > right || r < left) return;
    if (l >= left && r <= right) {
        upd(v, x);
        return;
    }
    push(v);
    int m = (l + r) / 2;
    upd(v * 2, l, m, left, right, x);
    upd(v * 2 + 1, m + 1, r, left, right, x);
    Max[v] = max(Max[v * 2], Max[v * 2 + 1]);
}

int get(int v, int l, int r, int left, int right) {
    if (l > right || r < left) return -1;
    if (l >= left && r <= right) return max(n, Max[v]);

    push(v);
    int m = (l + r) / 2;
    return max(get(v * 2, l, m, left, right), get(v * 2 + 1, m + 1, r, left, right));
}

void build(int v, int l, int r) {
    if (l == r) {
        Max[v] = l;
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    Max[v] = Max[v * 2 + 1];
}

void solve() {
    int m;
    cin >> n >> k >> m;
    build(1, 0, max_n);

    set<pii> a;
    multiset<int> arr;
    arr.emplace(0);

    while(m--) {
        pii b;
        cin >> b.first >> b.second;

        int num = abs(b.first - k) + b.second - 1;

        if (a.count(b)) {
            a.erase(b);
            upd(1, 0, max_n, 0, num, -1);
            arr.erase(arr.find(num));
        }else{
            a.emplace(b);
            upd(1, 0, max_n, 0, num, 1);
            arr.emplace(num);
        }  
        int temp = *(--arr.end());
        cout << get(1, 0, max_n, 0, temp) - n << endl;
    }
}


signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}