#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

int n, m, atk[111], def[111], ciel[111], val, jiroatk, jirodef;
string ss;
multiset<int> s;

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, n) {
        cin >> ss >> val;
        if (ss == "ATK") atk[jiroatk++] = val;
        else def[jirodef++] = val;
    }
    REP (i, m) cin >> ciel[i];
    sort(atk, atk + jiroatk);
    sort(def, def + jirodef);
    sort(ciel, ciel + m);
    int ans1 = 0;
    int cur = m - 1;
    REP (i, jiroatk) {
        if (cur >= 0 && ciel[cur] > atk[i]) {
            ans1 += ciel[cur] - atk[i];
            cur--;
        } else break;
    }
    REP (i, m) s.insert(ciel[i]);
    int ans2 = 0;
    REP (i, jirodef) {
        auto it = s.upper_bound(def[i]);
        if (it == s.end()) {
            cout << ans1;
            return 0;
        }
        s.erase(it);
    }
    REP (i, jiroatk) {
        auto it = s.lower_bound(atk[i]);
        if (it == s.end()) {
            cout << ans1;
            return 0;
        }
        ans2 += (*it) - atk[i];
        s.erase(it);
    }
    for (int i: s) ans2 += i;
    cout << max(ans1, ans2);
}