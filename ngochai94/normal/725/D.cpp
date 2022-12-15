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

long long n, t0, w0, t, w;
multiset<long long> pos;
vector<pair<long long, long long> > les;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> t0 >> w0;
    //pos.clear();
    FOR (i, 1, n - 1)
    {
        cin >> t >> w;
        if (t <= t0) les.pb({t, w});
        else pos.insert(w - t + 1);
    }
    //BUG(pos.size());
    sort(les.begin(), les.end());
    int ans = pos.size() + 1;
    int cur = ans;
    //BUG(ans);
    while (!pos.empty())
    {
        auto it = pos.begin();
        if (t0 < *it) break;
        t0 -= *it;
        //BUG(t0);
        pos.erase(it);
        cur--;
        //BUG(les.back().first);
        while (!les.empty() && les.back().first > t0)
        {
            pos.insert(les.back().second - les.back().first + 1);
            les.pop_back();
            cur++;
        }
        ans = min(ans, cur);
        //BUG(cur);
        //BUG(pos.size());
    }
    cout << ans;
}