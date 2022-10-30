#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
 
signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    vector<int> l(n), r(n); 
 
    vector<pii> sc;
 
    for(int i = 0;i < n;i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (temp2 >= m / 2) temp2 -= m / 2;
        l[i] = (temp2 - (k - 1) + m / 2) % (m / 2);
        r[i] = (temp2 + m / 2) % (m / 2);
 
        //cout << l[i] << " " << r[i] << endl;
        if (r[i] >= l[i]) {
            sc.emplace_back(l[i], 1);
            sc.emplace_back(r[i], 2);
        }else {
            sc.emplace_back(0, 1);
            sc.emplace_back(r[i], 2);
            sc.emplace_back(l[i], 1);
        }
    }
 
    sort(sc.begin(), sc.end());
 
    int cnt = 0;
    int res = inf, time_res = 0;
 
    int last = 0;
    for(auto i : sc) {
        
        if (i.first != last) {
            if (res > cnt) {
                res = cnt;
                time_res = i.first - 1;
            }
            last = i.first;
        }
 
        if (i.second == 1) cnt++;
        else cnt--;
    }

    if (res > cnt) {
        res = cnt;
        time_res = sc[sc.size() - 1].first;
    }
 
    cout << res << " " << (time_res + k) % (m / 2) << endl;
 
    for(int i = 0;i < n;i++) {
        bool good = false;
        if (r[i] >= l[i]) {
            if (time_res >= l[i] && time_res < r[i]) good = true;
        }else {
            if (time_res < r[i] || time_res >= l[i]) good = true;
        }
 
        if (good) cout << i + 1 << " ";
    }
}