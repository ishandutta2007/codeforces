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
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    int n;
    cin >> n;
    cout << n + n / 2 << endl;
    for(int i = 2;i <= n;i += 2)
        cout << i << " ";

    for(int i = 1;i <= n;i += 2)
        cout << i << " ";
    for(int i = 2;i <= n;i += 2) 
        cout << i << " ";
}