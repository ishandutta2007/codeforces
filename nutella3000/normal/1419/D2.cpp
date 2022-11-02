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
    vector<int> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
 
    sort(all(a));
 
    vector<int> res(n);
    int id = 0;
    for(int i = 1;i < n;i += 2) {
        res[i] = a[id++];
    }
 
    int q = 0;
    //bool good = true;
    for(int i = 0;i < n;i += 2) {
        /*if (a[id] == res[i + 1] && n % 2 == 1 && good) {
            good = false;
            res[n - 1] = a[id--];
            continue;
        }*/
        if (id < 0) continue;
        res[i] = a[id++];
    }

    for(int i = 1;i < n - 1;i++)
        if (res[i] < res[i - 1] && res[i] < res[i + 1]) q++;
 
    cout << q << endl;
    for(int i : res)
        cout << i << " ";
}