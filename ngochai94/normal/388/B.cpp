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

int n, cur, lis[33];
string ans[1111], s;

void connect(int x, int y) {
    ans[x][y] = ans[y][x] = 'Y';
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    s = "";
    REP (i, 1000) s += 'N';
    REP (i, 1000) ans[i] = s;
    cur = 100;
    connect(0, 2);
    connect(0, 3);
    connect(2, cur);
    connect(3, cur);
    REP (i, 30) {
        connect(cur, cur + 1);
        cur++;
    }
    lis[1] = cur;
    connect(0, ++cur);
    REP (i, 31) {
        connect(cur, cur + 1);
        cur++;
    }
    lis[0] = cur;
    FOR (i, 2, 30) {
        connect(i * 2 + 1, i * 2 - 1);
        connect(i * 2 + 1, i * 2 - 2);
        connect(i * 2, i * 2 - 1);
        connect(i * 2, i * 2 - 2);
        connect(i * 2, ++cur);
        connect(i * 2 + 1, cur);
        REP (j, 31 - i) {
            connect(cur, cur + 1);
            cur++;
        }
        lis[i] = cur;
    }
    REP (i, 31) if ((1 << i) & n) connect(1, lis[i]);
    cout << 1000 << endl;
    REP (i, 1000) cout << ans[i] << endl;
}