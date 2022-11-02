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

    int n;
    cin >> n;
    vector<int> res(n);
    int id = 0;
    for(int i = 1;i < n;i++) {
        cout << "? " << id + 1 << " " << i + 1 << endl;
        int num1, num2;
        cin >> num1;
        cout << "? " << i + 1 << " " << id + 1 << endl;
        cin >> num2;
        if (num1 < num2) {
            res[i] = num2;
        }else {
            res[id] = num1;
            id = i;
        }
    }

    res[id] = n;
    cout << "! ";
    for(int i : res)
        cout << i << " ";

    cout << endl;
}