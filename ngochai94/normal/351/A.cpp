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

int n, tmp, val, cnt;
char c;

int main(){
    // ios::sync_with_stdio(0);
    cin >> n;
    int ans = 0;
    REP (i, 2 * n) {
        cin >> tmp >> c >> val;
        if (!val) cnt++;
        ans += val;
    }
    ans -= n * 1000;
    while (cnt && abs(ans + 1000) < abs(ans)) {
        ans += 1000;
        cnt--;
    }
    ans = abs(ans);
    printf("%d.%03d", ans / 1000, ans % 1000);
}