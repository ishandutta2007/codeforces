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
    multimap<int, string> a[m];

    for(int i = 0;i < n;i++) {
        string s;
        int point, id;
        cin >> s >> id >> point;
        id--;
        a[id].emplace(point, s);
    }

    for(int i = 0;i < m;i++) {
        auto it = --a[i].end();

        string s1 = it -> second;

        --it;
        a[i].erase(--a[i].end());

        string s2 = it -> second;
        int num = it -> first;

        --it;
        a[i].erase(--a[i].end());

        if (a[i].empty() || it->first < num) cout << s1 << " " << s2 << endl;
        else cout << "?" << endl;
    }
}