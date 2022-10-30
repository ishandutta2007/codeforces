#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e9 + 7;
const int max_n = 5e5 + 4;

int a[max_n];

 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n);
    vector<int> id(n);
    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        id[i] = i;
    }

    sort(id.begin(), id.end(), [](int v1, int v2) {return a[v1] < a[v2];});

    bool bad = false;
    vector<bool> used(n);
    for(int i : id) {
        vector<int> temp;
        for(int j : gr[i]) if (used[j]) 
            temp.emplace_back(a[j]);

        sort(temp.begin(), temp.end());

        int res = 1;
        for(int i : temp) {
            if (res == i) res++;
            if (i < res) continue;
            break;
        }

        if (res != a[i]) bad = true;
        used[i] = true;
    }
    if (bad) cout << -1;
    else {
        for(int i : id) cout << i + 1 << " ";
    }
}