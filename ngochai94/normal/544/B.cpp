#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

int n, k;
char ans[111][111];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> k;
    REP (i, n) REP (j, n) {
        if ((i + j) % 2 == 0 && k) {
            k--;
            ans[i][j] = 'L';
        } else ans[i][j] = 'S';
    }
    if (k) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    REP (i, n) {
        REP (j, n) cout << ans[i][j];
        cout << endl;
    }
}