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
typedef double ld;
 
const int inf = 1e16;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++)
            cin >> a[i];

        vector<bool> used(n);

        vector<int> res;
        int num = a[max_element(all(a)) - a.begin()];

        for(int it = 0;it < n;it++) {
            int id = -1;
            for(int i = 0;i < n;i++) {
                if (used[i] || (id != -1 && gcd(num, a[i]) < gcd(num, a[id]))) continue;
                id = i;
            }
            used[id] = true;
            res.emplace_back(a[id]);
            num = gcd(num, a[id]);
        }

        for(int i : res)
            cout << i << " ";

        cout << endl;
    }
}