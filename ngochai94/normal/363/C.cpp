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

string s, ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> s;
    ans = "";
    int cnt = 0;
    int bef = 0;
    char lat = ' ';
    for (char c: s) {
        // cout << c << ' ' << cnt << ' ' << bef << endl;
        if (c == lat) {
            if (!cnt && !bef) {
                ans += c;
                cnt++;
            }
        } else {
            if (cnt) bef = 1;
            else bef = 0;
            cnt = 0;
            ans += c;
        }
        lat = c;
    }
    cout << ans;
}