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

int a, b;

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> a >> b;
    int x1 = 0;
    int y1 = a;
    int x2 = b;
    int y2 = 0;
    while (--y1) {
        while (y1 * y1 + x1 * x1 < a * a) x1++;
        while (x1 * x2 + y1 * y2 > 0) {
            x2--;
            while (x2 * x2 + y2 * y2 < b * b) y2--;
        }
        if (x1 != x2 && y1 * y1 + x1 * x1 == a * a && x1 * x2 + y1 * y2 == 0 && x2 * x2 + y2 * y2 == b * b) {
            cout << "YES" << endl;
            cout << "0 0" << endl;
            cout << x1 << ' ' << y1 << endl;
            cout << x2 << ' ' << y2 << endl;
            return 0;
        }
    }
    cout << "NO";
}