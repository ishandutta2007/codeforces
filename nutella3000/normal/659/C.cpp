#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int id = 0;
    vector<int> res;

    for(int i = 0;i < n;i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for(int num = 1;num <= m;num++) {
        if (id != n && a[id] == num) {
            id++;
            continue;
        }
        res.emplace_back(num);
        m -= num;
    }

    cout << res.size() << endl;
    for(int i : res) 
        cout << i << " ";
}