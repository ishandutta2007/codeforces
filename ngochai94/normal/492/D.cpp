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

long long n, x, y, hp;

bool check(long long t) {
    return t / x + t / y >= hp;
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> x >> y;
    while (n--) {
        cin >> hp;
        long long high = x * hp + 1, low = 0;
        while (high > low) {
            long long chs = (high + low) / 2;
            if (check(chs)) high = chs;
            else low = chs + 1;
        }
        if (low % y == 0 && low % x == 0) cout << "Both" << endl;
        else if (low % y == 0) cout << "Vanya" << endl;
        else cout << "Vova" << endl;
    }
}