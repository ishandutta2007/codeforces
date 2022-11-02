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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    } 

    int id = 0;
    for(int i = 0;i < n;i += 2) {
        b[id++] = a[i];
    }
    for(int i = 1;i < n;i += 2) {
        b[id++] = a[i];
    }
    for(int i = 0;i < n;i++) b.emplace_back(b[i]);

    int res = 0;
    int sum = 0;

    for(int i = 0;i < (n + 1) / 2;i++) sum += b[i];
    res = sum;
    for(int i = (n + 1) / 2;i < 2 * n;i++) {
        sum += b[i] - b[i - (n + 1) / 2];
        res = max(res, sum);
    }

    cout << res;
}