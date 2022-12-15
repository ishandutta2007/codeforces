#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

int n, ind, ans[2], cur;
string s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> s;
    for (char c: s)
    {
        if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A') cur++;
        else
        {
            if (!ind) ans[ind] = max(ans[ind], cur);
            else if (cur) ans[ind]++;
            cur = 0;
        }
        if (c == '(') ind = 1;
        if (c == ')') ind = 0;
    }
    ans[0] = max(ans[0], cur);
    cout << ans[0] << ' ' << ans[1];
}