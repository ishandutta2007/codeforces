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

long long n, cntu[1000006], cntd[1000006], preu[1000006], pred[1000006];
string s;
vector<long long> lisu, lisd;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> s;
    lisd.pb(0);
    lisu.pb(0);
    FOR (i, 1, n)
    {
        if (s[i - 1] == 'D') cntd[i]++;
        else cntu[i]++;
        cntd[i] += cntd[i - 1];
        cntu[i] += cntu[i - 1];
        if (s[i - 1] == 'D') pred[i] += i;
        else preu[i] += i;
        pred[i] += pred[i - 1];
        preu[i] += preu[i - 1];
        if (s[i - 1] == 'D')
        {
            lisd.pb(lisd.back() + i);
        }
        else
        {
            lisu.pb(lisu.back() + i);
        }
    }
    FOR (i, 1, n)
    {
        if (s[i - 1] == 'U')
        {
            long long down_after = cntd[n] - cntd[i];
            long long up_before = cntu[i - 1];
            if (down_after <= up_before) cout << 2 * (pred[n] - pred[i])
                + 2 * ( - lisu[cntu[i - 1]] + lisu[cntu[i - 1] - down_after])
                + n - i + 1 << ' ';
            else cout << 2 * (lisd[cntd[i] + up_before + 1] - i - lisd[cntd[i]] - lisu[cntu[i - 1]] + lisu[cntu[i - 1] - up_before])
                + i << ' ';
        }
        else
        {
            long long down_after = cntd[n] - cntd[i];
            long long up_before = cntu[i - 1];
            //BUG(lisd[cntd[i] + up_before] - lisd[cntd[i]] - i * up_before);
            if (up_before <= down_after) cout << 2 * (lisd[cntd[i] + up_before] - lisd[cntd[i]]
                        - lisu[cntu[i - 1]] + lisu[cntu[i - 1] - up_before]) + i << ' ';
            else cout << 2 * (lisd[cntd[i] + down_after] - lisd[cntd[i]]
                        - lisu[cntu[i - 1]] + lisu[cntu[i - 1] - down_after - 1] + i) + n - i + 1 << ' ';
        }
    }
}