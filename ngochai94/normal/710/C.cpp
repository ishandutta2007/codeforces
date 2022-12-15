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

int n, ans[50][50];
vector<int> odd, even;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n * n)
    {
        if (i & 1) odd.pb(i);
        else even.pb(i);
    }
    FOR (i, 1, n)
    {
        ans[i][n / 2 + 1] = odd.back();
        odd.pop_back();
        if (i <= n / 2)
        {
            FOR (ii, 1, i - 1)
            {
                ans[i][n / 2 + 1 + ii] = odd.back();
                odd.pop_back();
                ans[i][n / 2 + 1 - ii] = odd.back();
                odd.pop_back();
            }
        }
        else
        {
            FOR (ii, 1, n - i)
            {
                ans[i][n / 2 + 1 + ii] = odd.back();
                odd.pop_back();
                ans[i][n / 2 + 1 - ii] = odd.back();
                odd.pop_back();
            }
        }
        FOR (j, 1, n) if (!ans[i][j])
        {
            ans[i][j] = even.back();
            even.pop_back();
        }
        FOR (j, 1, n) cout << ans[i][j] << ' ';
        cout << endl;
    }
}