#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double


const int inf = 1e9 + 7;

int n;

int que(int id, bool inv) {
    cout << "? ";
    for (int i = 0; i < n; ++i) {
        if (i == id) cout << !inv + 1 << " ";
        else cout << inv + 1 << " ";
    }
    cout << endl;
    int v; cin >> v;
    return v - 1;
}

void run() {
    cin >> n;
    vector<int> ls(n, -1);
    for (int i = 0; i < n; ++i) {
        int v = que(i, false);
        if (v < i && v != -1) ls[v] = i;
    }
    for (int i = 0; i < n; ++i) {
        int v = que(i, true);
        if (v < i) ls[i] = v;
    }
    int lst = -1;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        int id = 0;
        for (int j = 0; j < n; ++j) {
            if (ls[j] == lst) id = j;
        }
        res[id] = i;
        lst = id;
    }
    cout << "! ";
    for (int i : res)
        cout << i + 1 << " ";
    
    cout << endl;
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}