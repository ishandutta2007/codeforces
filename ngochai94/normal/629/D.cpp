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

long long n, ans, r, h;
set<pair<long long, long long> > s;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        cin >> r >> h;
        h *= r * r;
        ans = max(ans, h);
        auto it = s.lower_bound({h, 0});
        if (it == s.begin())
        {
            s.insert({h, h});
        }
        else
        {
            it--;
            long long tmp = it->_2 + h;
            s.insert({h, tmp});
            ans = max(ans, tmp);
            while (1)
            {
                it = s.lower_bound({h, 0});
                if (it->_2 < tmp)
                {
                    s.erase(it);
                    continue;
                }
                it++;
                if (it != s.end() && it->_2 <= tmp)
                {
                    s.erase(it);
                    continue;
                }
                break;
            }
        }
    }
    cout << setprecision(11) << pi * ans;
}