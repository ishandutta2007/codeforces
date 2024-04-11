#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e1+10, MOD = 1e9+7;

int m, n;

int qry(int x) {
    cout << x << endl;
    int ans; cin >> ans;
    if (!ans) {
        exit(0);
    }
    return ans;
}

bool lie[MAXN];
void solve(){
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int c = qry(1);
        if (c == -1) lie[i] = 1;
    }
    int cur_qry = 0;
    int lo = 0, hi = m+1, mid = (lo + hi)/2;
    while (lo < mid && mid < hi) {
        int c = qry(mid);
        if (lie[cur_qry]) c *= -1;
        if (c == -1) hi = mid;
        else lo = mid;

        cur_qry = (cur_qry+1)%n;
        mid = (lo+hi)/2;
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}