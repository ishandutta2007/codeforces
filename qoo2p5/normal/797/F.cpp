#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

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

const int N = 5005;

struct Stack {
    int ptr = 0;
    pair<ll, ll> a[N];
    
    void push(ll x) {
        if (ptr == 0) {
            a[ptr] = {x, x};
        } else {
            a[ptr] = {x, min(x, a[ptr - 1].second)};
        }
        ptr++;
    }
    
    void clear() {
        ptr = 0;
    }
    
    ll pop() {
        return a[--ptr].first;
    }
    
    ll get_min() {
        return ptr ? a[ptr - 1].second : LINF;
    }
};

struct Queue {
    Stack s1, s2;
    
    void push(ll x) {
        s1.push(x);
    }
    
    ll get_min() {
        return min(s1.get_min(), s2.get_min());
    }
    
    void pop() {
        if (!s2.ptr) {
            while (s1.ptr) {
                s2.push(s1.pop());
            }
        }
        
        s2.pop();
    }
    
    void clear() {
        s1.ptr = 0;
        s2.ptr = 0;
    }
};

int n, m;
int x[N];
pair<int, int> y[N];

ll dp[N], ndp[N];

ll cost(int i, int j) {
    return abs(x[i] - y[j].first);
}

void run() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    for (int i = 0; i < m; i++) {
        cin >> y[i].first >> y[i].second;
    }
    sort(y, y + m);
    
    fill(dp, dp + N, LINF);
    dp[0] = 0;
    Queue q;
    
    for (int j = 1; j <= m; j++) {
        copy(dp, dp + N, ndp);
        ll cur_cost = 0;
        for (int i = 1; i <= n; i++) {
            cur_cost += cost(i - 1, j - 1);
            if (dp[i] < LINF) dp[i] -= cur_cost;
        }
        
        q.clear();
        q.push(dp[0]);
        cur_cost = 0;
        for (int i = 1; i <= n; i++) {
            int l = i - min(i, y[j - 1].second);
            if (l - 1 >= 0) {
                q.pop();
            }
            cur_cost += cost(i - 1, j - 1);
            ndp[i] = min(ndp[i], q.get_min() + cur_cost);
            q.push(dp[i]);
        }
        
        copy(ndp, ndp + N, dp);
    }
    
    cout << (dp[n] < LINF ? dp[n] : -1) << "\n";
}