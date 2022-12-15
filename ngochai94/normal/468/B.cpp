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

int n, a, b, ans[100005], val;
map<int, int> lis;
queue<pair<int, int> > q;
vector<int> toClear;

void clr() {
    for (int i: toClear) ans[i] = -1;
    toClear.clear();
}

bool check(int x, int y) {
    while(!q.empty()) q.pop();
    q.push({x, y});
    ans[lis[x]] = y;
    toClear.pb(lis[x]);
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (y) {
            if (!lis.count(b - x) || ans[lis[b - x]] == 0) {
                clr();
                return false;
            }
            if (lis.count(a - x) && ans[lis[a - x]] == 0) {
                clr();
                return false;
            }
            if (ans[lis[b - x]] == -1) {
                ans[lis[b - x]] = 1;
                q.push({b - x, 1});
                toClear.pb(lis[b - x]);
            }
            if (lis.count(a - x) && ans[lis[a - x]] == -1) {
                ans[lis[a -x]] = 1;
                q.push({a - x, 1});
                toClear.pb(lis[a - x]);
            }
        } else {
            if (!lis.count(a - x) || ans[lis[a - x]] == 1) {
                clr();
                return false;
            }
            if (lis.count(b - x) && ans[lis[b - x]] == 1) {
                clr();
                return false;
            }
            if (ans[lis[a - x]] == -1) {
                ans[lis[a - x]] = 0;
                q.push({a - x, 0});
                toClear.pb(lis[a - x]);
            }
            if (lis.count(b - x) && ans[lis[b - x]] == -1) {
                ans[lis[b - x]] = 0;
                q.push({b - x, 0});
                toClear.pb(lis[b - x]);
            }
        }
    }
    toClear.clear();
    return true;
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    REP (i, n) {
        cin >> val;
        lis[val] = i;
    }
    if (a == b) {
        for (auto i: lis) if (!lis.count(a - i.first)) {
            cout << "NO";
            return 0;
        }
        cout << "YES" << endl;
        REP (i, n) cout << 0 << ' ';
        return 0;
    }
    reset(ans, -1);
    for (auto i: lis) if (!~ans[i.second]) {
        // BUG(i.first);
        if (check(i.first, 0)) continue;
        if (!check(i.first, 1)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    REP (i, n) cout << ans[i] << ' ';
}