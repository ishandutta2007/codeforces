#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int lis1[100005], lis2[100005];
string s1, s2;

void solve()
{
    cin >> s1 >> s2;
    int n = max(s1.size(), s2.size());
    REP (i, s1.size()) lis1[i] = s1[s1.size() - 1 - i] - '0';
    REP (i, s2.size()) lis2[i] = s2[s2.size() - 1 - i] - '0';
    long long a = lis1[n] - lis2[n], b = lis1[n - 1] - lis2[n - 1];
    FORD (i, n - 1, 1)
    {
        long long tmp = b;
        b = lis1[i - 1] - lis2[i - 1] + a;
        a += tmp;
        if (a > 0 && a + b > n + 10)
        {
            cout << '>';
            return;
        }
        if (a < 0 && a + b < - n - 10)
        {
            cout << '<';
            return;
        }
    }
    if (!a && !b) cout << '=';
    else if (a * (sqrt(5) + 1) / 2 + b > 0) cout << '>';
    else cout << '<';
}

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif LOCAL
    ios::sync_with_stdio(0);
    int ntest = 1;
    //cin >> t;
    while (ntest--)
    {
        solve();
    }
}