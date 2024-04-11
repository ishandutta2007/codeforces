#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, k, p, val;
vector<int> odd, even;

int main(){
    // ios::sync_with_stdio(0);
    cin >> n >> k >> p;
    REP (i, n) {
        cin >> val;
        if (val & 1) odd.pb(val);
        else even.pb(val);
    }
    if (k - p <= odd.size() && (odd.size() - k + p) % 2 == 0 && p <= (odd.size() - k + p) / 2 + even.size()) {
        cout << "YES" << endl;
    } else {
        cout << "NO";
        return 0;
    }
    if (!p) {
        REP (i, k - p - 1) {
            cout << "1 " << odd.back() << endl;
            odd.pop_back();
        }
        cout << even.size() + odd.size() << ' ';
        for (int i: odd) cout << i << ' ';
        for (int i: even) cout << i << ' ';
        return 0;
    }
    REP (i, k - p) {
        cout << 1 << ' ' << odd.back() << endl;
        odd.pop_back();
    }
    REP (i, p - 1) {
        if (even.size()) {
            cout << "1 ";
            cout << even.back() << endl;
            even.pop_back();
        } else {
            cout << "2 ";
            cout << odd.back() << ' ';
            odd.pop_back();
            cout << odd.back() << endl;
            odd.pop_back();
        }
    }
    cout << even.size() + odd.size() << ' ';
    for (int i: odd) cout << i << ' ';
    for (int i: even) cout << i << ' ';
}