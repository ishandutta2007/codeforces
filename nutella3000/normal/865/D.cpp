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
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
priority_queue<int> q;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    int res = 0;
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        if (q.size() && -q.top() < v) {
            res += v + q.top();
            q.pop();
            q.emplace(-v);
        }
        q.emplace(-v);
    }    
    cout << res;
}