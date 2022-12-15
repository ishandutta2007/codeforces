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

long long n, r, need[200005], l[200005], t[200005], pre[200005], add;
vector<long long> ans;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    scanf("%lld %lld", &n, &r);
    REP (i, n) scanf("%lld", &l[i]);
    REP (i, n) scanf("%lld", &t[i]);
    FOR (i, 1, n - 1) pre[i] = pre[i - 1] + l[i - 1];
    REP (i, n)
    {
        t[i] = min(t[i], 2 * l[i]);
        need[i] = max(0ll, 2 * l[i] - t[i]);
        if (l[i] > t[i])
        {
            cout << -1;
            return 0;
        }
    }
    long long cur = 0;
    long long moment = 0;
    REP (i, n) if (need[i])
    {
        if (cur < pre[i])
        {
            moment += 2 * (pre[i] - cur);
            cur = pre[i];
        }
        long long tmp = need[i] - (cur - pre[i]);
        if (tmp <= 0) continue;
        if (tmp / r + add > 100005)
        {
            add += tmp / r;
            cur += r * (tmp / r);
            moment += r * (tmp / r);
            tmp -= r * (tmp / r);
        }
        else
        {
            while (tmp >= r)
            {
                tmp -= r;
                if (ans.size() < 100005) ans.pb(moment);
                add++;
                cur += r;
                moment += r;
            }
        }

        if (tmp > 0)
        {
            moment += (pre[i] + l[i] - tmp - cur) * 2;
            cur = pre[i] + l[i] - tmp;
            if (ans.size() < 100005) ans.pb(moment);
            add++;
            cur += r;
            moment += r;
        }
    }
    printf("%lld\n", add);
    if (add <= 100000) for (auto i: ans) printf("%lld ", i);
}