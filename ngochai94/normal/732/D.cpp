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

int n, m, lis[100005], pre[100005], passed[100005];

bool check(int x)
{
    reset(passed, 0);
    int has = x - m;
    int cnt = 0;
    int ahead = 0;
    FORD (i, x, 1)
    {
        //cout << i << ' ' << has << endl;
        if (lis[i] && !passed[lis[i]])
        {
            //cout << 'a' << endl;
            if (has >= pre[lis[i]])
            {
                //cout << 1231231 << ' ' << lis[i] << endl;
                cnt++;
                has -= pre[lis[i]];
                ahead += pre[lis[i]];
                passed[lis[i]] = 1;
            }
            else return false;
            continue;
        }
        //cout << i << ' ' << has << endl;
        if (!ahead) has--;
        else ahead--;
    }
    return cnt == m;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    FOR (i, 1, n) cin >> lis[i];
    FOR (i, 1, m) cin >> pre[i];
    //check(9);return 0;
    int high = n + 1, low = 1;
    while (high > low)
    {
        int chs = (high + low) / 2;
        if (check(chs)) high = chs;
        else low = chs + 1;
    }
    if (low == n + 1) cout << -1;
    else cout << low;
}