#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e10;
 
struct w {
    int a, b, id;
    w(int a, int b, int id) : a(a), b(b), id(id) {}
    w() {}
};
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<w> a(n + 1);
    vector<int> res;
    for(int i = 0;i < n;i++)
        cin >> a[i].a;
    for(int i = 0;i < n;i++)
        cin >> a[i].b;
    for(int i = 0;i < n;i++)
        a[i].id = i + 1;

    a[n] = w(0, 0, n);
    sort(a.begin(), a.begin() + n, [](w v1, w v2) {return v1.a > v2.a;});

    res.emplace_back(a[0].id);
    for(int i = 1;i < n;i += 2) {
        res.emplace_back(a[i].b > a[i + 1].b ? a[i].id : a[i + 1].id);
    }

    cout << res.size() << endl;
    for(int i : res)
        cout << i << " ";
}