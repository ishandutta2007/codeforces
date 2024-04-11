#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e9 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a((int) 2e7);

    vector<int> d((int) 2e7);

    for(int i = 2;i < 2e7;i++) {
        if (d[i] != 0) 
            continue;
        d[i] = i;
        if (i > 1e4) 
            continue;
        for(int j = i * i;j < 2e7;j += i) {
            if (d[j] == 0)
                d[j] = i;
        }
    }
    //cout << "done" << endl;

    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;

        while(v != 1) {
            //cout << v << " " << d[v] << endl;
            int temp = d[v];
            int temp1 = temp;
            while(v % temp == 0) {
                v /= temp;
                a[temp1]++;
                temp1 *= temp;
            }
        }
    }

    //cout << a[3] << endl;
    int res = inf;
    for(int i : a) 
        if (i != n)
            res = min(res, n - i);

    if (res == n) 
        cout << -1;
    else
        cout << res;
}