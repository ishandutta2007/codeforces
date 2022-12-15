#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

long long ans, n;
string s;
char c;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> c;
    n--;
    ans = (n / 4) * 16;
    n %= 4;
    if (n > 1) n -= 2;
    if (n) ans += 7;
    if (c == 'f') ans += 1;
    if (c == 'e') ans += 2;
    if (c == 'd') ans += 3;
    if (c == 'a') ans += 4;
    if (c == 'b') ans += 5;
    if (c == 'c') ans += 6;
    cout << ans;
}