#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

int n, p1, p2, s, lis[111];
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> s;
        REP (i, s) cin >> lis[i];
        REP (i, s / 2) {
            p1 += lis[i];
            p2 += lis[s - 1 - i];
        }
        if (s & 1) v.pb(lis[s / 2]);
    }
    sort(v.begin(), v.end());
    while (!v.empty()) {
        p1 += v.back();
        v.pop_back();
        if (!v.empty()) {
            p2 += v.back();
            v.pop_back();
        }
    }
    cout << p1 << ' ' << p2;
}