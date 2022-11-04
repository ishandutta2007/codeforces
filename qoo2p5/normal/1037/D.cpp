#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

const int N = (int) 2e5 + 123;

int n;
vector<int> g[N];
bool used[N];

void NO() {
    cout << "NO\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    queue<vector<int>> q;
    q.push({a[0]});
    int ptr = 0;
    used[a[0]] = true;
    if (a[0] != 1) NO();
    while (!q.empty()) {
        auto what = q.front();
        q.pop();
        sort(what.begin(), what.end());
        int k = (int) what.size();
        if (ptr + k > n) {
            NO();
        }
        vector<int> our;
        for (int i = 0; i < k; i++) {
            our.push_back(a[ptr]);
            ptr++;
        }
        vector<int> orig = our;
        sort(our.begin(), our.end());
        if (our != what) {
            NO();
        }
        for (int v : orig) {
            vector<int> nxt;
            for (int u : g[v]) {
                if (used[u]) continue;
                used[u] = true;
                nxt.push_back(u);
            }
            q.push(nxt);
        }
    }

    cout << "YES\n";

    return 0;
}