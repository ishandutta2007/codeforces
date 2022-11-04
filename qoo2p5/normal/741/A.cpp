#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;

const int N = 101;
int n;
int nxt[N];
int st[N];
bool used[N];

int dfs(int v) {
    used[v] = true;
    
    if (!used[nxt[v]]) {
        return dfs(nxt[v]) + 1;
    } else {
        return 1;
    }
}

ll nok(ll a, ll b) {
    return a * b / __gcd(a, b);
}

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
        st[nxt[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (st[i] != 1) {
            cout << "-1\n";
            return;
        }
    }
    
    vector<int> lens;
    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int l = dfs(i);
            if (l != 1) {
                lens.push_back(l % 2 == 0 ? l / 2 : l);
            }
        }
    }
    
    ll cur = 1;
    
    for (ll l : lens) {
        cur = nok(cur, l);
    }
    
    cout << cur << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}