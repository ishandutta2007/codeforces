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

int a, b;
vector<int> ans;

bool solve(int x) {
    if (x == a) {
        ans.pb(a);
        return true;
    }
    if (!x) return 0;
    if (x % 2 == 0 && solve(x / 2)) {
        ans.pb(x);
        return true;
    }
    if (x % 10 == 1 && solve(x / 10)) {
        ans.pb(x);
        return true;
    }
    return false;
}

int main(){
    // ios::sync_with_stdio(0);
    cin >> a >> b;
    if (solve(b)) {
        cout << "YES" << endl << ans.size() << endl;
        for (int i: ans) cout << i << ' ';
    }
    else cout << "NO";
}