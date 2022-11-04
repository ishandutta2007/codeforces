#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) (int) (x).size()

const int INF = (int) 1e9 + 123;

void run();

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

const int N = (int) 1e5 + 2;
const int L = (int) log2(N) + 2;
const int M = 1000;

struct Tree {
    int l, r, sum;
    
    Tree() : l(-1), r(-1), sum(0) {}
};

int ptr = 1;
Tree tree[N * L];

int get_l(int t) {
    return t == -1 ? -1 : tree[t].l;
}

int get_r(int t) {
    return t == -1 ? -1 : tree[t].r;
}

int add(int t, int tl, int tr, int ind, int val) {
    int v = ptr++;
    if (t != -1) {
        tree[v] = tree[t];
    }
    
    tree[v].sum += val;
    
    if (tl == tr - 1) {
        return v;
    }
    
    int tm = (tl + tr) >> 1;
    if (ind < tm) {
        tree[v].l = add(get_l(v), tl, tm, ind, val);
    } else {
        tree[v].r = add(get_r(v), tm, tr, ind, val);
    }
    
    return v;
}

int get(int t, int tl, int tr, int l, int r) {
    if (t == -1 || tl >= r || tr <= l) {
        return 0;
    }
    
    if (l <= tl && tr <= r) {
        return tree[t].sum;
    }
    
    int tm = (tl + tr) >> 1;
    return get(get_l(t), tl, tm, l, r) + get(get_r(t), tm, tr, l, r);
}

int n;
int a[N];
int pos[N];
int prv[N];
int rev[N];
bool vis[N];

int calc_diff(int l, int r) {
    return get(rev[r], 0, N, 0, l) - get(rev[l - 1], 0, N, 0, l);
}

int solve(int k) {
    if (k > M) {
        int res = 0;
        int cur = 1;
        while (cur <= n) {
            int left = 1;
            int right = n - cur + 2;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (calc_diff(cur, cur + mid - 1) <= k) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            cur += left;
            res++;
        }
        
        return res;
    } else {
        int res = 0;
        int cur = 1;
        while (cur <= n) {
            int t = 1;
            int cnt = 0;
            for (; t <= n - cur + 1 && (vis[a[cur + t - 1]] || cnt + 1 <= k); t++) {
                if (!vis[a[cur + t - 1]]) {
                    vis[a[cur + t - 1]] = 1;
                    cnt++;
                }
            }
            --t;
            
            for (int i = cur; i < cur + t; i++) {
                vis[a[i]] = 0;
            }
            
            cur += t;
            res++;
        }
        
        return res;
    }
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        prv[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        rev[i] = add(rev[i - 1], 0, N, prv[i], 1);
    }
    
    for (int k = 1; k <= n; k++) {
        cout << solve(k) << " ";
    }
    cout << "\n";
}