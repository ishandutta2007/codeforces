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

int n, lis[111], ans;

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, 10000) {
        if (n >= i * (i + 1) / 2) {
            n -= i * (i + 1) / 2;
            ans++;
        }
        else {
            cout << ans;
            return 0;
        }
    }
}