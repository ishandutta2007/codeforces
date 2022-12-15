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

long long n, m, q, pre[200005], x, y;
vector<long long> ans;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m >> q;
    reset(pre, -1);
    long long each = n;
    REP (i, 2 * n)
    {
        long long tmp = (2 * m * i) % (2 * n);
        if(pre[tmp] == -1) pre[tmp] = i;
        //if (!tmp && i) each = min(each, i);
    }
    each *=  2 * m;
    while (q--)
    {
        cin >> x >> y;
        long long cur = (x - y) % (2 * n);
        cur += 2 * n;
        cur %= (2 * n);
        //BUG(pre[cur]);
        if (pre[cur] != -1)
        {
            long long curr = y + 2 * m * pre[cur];
            //while (cur < 0) cur +=each;
            ans.pb(curr);
        }
        cur = (2 * n - x - y) % (2 * n);
        cur += 2 * n;
        cur %= 2 * n;
        //BUG(pre[cur]);
        if (pre[cur] != -1)
        {
            long long curr = y + 2 * m * pre[cur];
            //while (cur < 0) cur +=each;
            ans.pb(curr);
        }
        cur = (x + y - 2 * m) % (2 * n);
        cur += 2 * n;
        cur %= 2 * n;
        //BUG(pre[cur]);
        if (pre[cur] != -1)
        {
            long long curr = 2 * m - y + 2 * m * pre[cur];
            //while (cur < 0) cur +=each;
            ans.pb(curr);
        }
        cur = (2 * n - x + y - 2 * m) % (2 * n);
        cur += 2 * n;
        cur %= 2 * n;
        //BUG(pre[cur]);
        if (pre[cur] != -1)
        {
            long long curr = 2 * m - y + 2 * m * pre[cur];
            //while (cur < 0) cur +=each;
            ans.pb(curr);
        }
        if (ans.empty()) cout << -1 << endl;
        else
        {
            //for (auto i: ans) cout << i << endl;
            sort(ans.begin(), ans.end());
            cout << ans[0] << endl;
            ans.clear();
        }
    }
}