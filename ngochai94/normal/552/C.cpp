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

int w, m;

int main(){
    ios::sync_with_stdio(0);
    cin >> w >> m;
    while (m) {
        int tmp = m % w;
        // BUG(tmp);
        if (tmp != 0 && tmp != 1) {
            if (tmp == w - 1) {
                m += w;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        m /= w;
    }
    cout << "YES";
}