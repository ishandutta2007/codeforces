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

long long n, lis[200005];

void solve()
{
    cin >> n;
    REP (i, n) cin >> lis[i];
    int st = 0;
    int ans = 0;
    while (st < n)
    {
        //BUG(st);
        ans++;
        int en = st;
        int i1 = -1, i2 = -1;
        while (en < n)
        {
            if (lis[en] != -1)
            {
                if (i1 == -1) i1 = en;
                else
                {
                    i2 = en;
                    break;
                }
            }
            en++;
        }
        //BUG(i1);
        //BUG(i2);
        if (i2 == -1) break;
        if ((lis[i2] - lis[i1]) % (i2 - i1))
        {
            st = en;
            continue;
        }
        long long gap = (lis[i2] - lis[i1]) / (i2 - i1);
        if (lis[i1] - gap * (i1 - st) <= 0)
        {
            st = en;
            continue;
        }
        long long cur = lis[i2] + gap;
        while (cur > 0 && en + 1 < n && (lis[en + 1] == -1 || lis[en + 1] == cur))
        {
            en++;
            cur += gap;
        }
        st = en + 1;
    }
    cout << ans;
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