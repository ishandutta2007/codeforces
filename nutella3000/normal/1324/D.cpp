#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> temp(n);
    for(int i = 0;i < n;i++) {
        cin >> temp[i];
    }
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        a[i] = temp[i] - v;
    }

    sort(all(a));

    int res = 0;
    int id = n - 1;

    /*for(int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;*/

    for(int i = 0;i < n;i++) {
        id = min(n - 1, id);
        while(id >= 0 && a[id] + a[i] > 0)
            id--;
        id++;
        res += n - max(id, i + 1);
    }

    cout << res;
}