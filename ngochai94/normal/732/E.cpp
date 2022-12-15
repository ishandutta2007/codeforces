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

int n, m, p[200005], tmp, soc[200005];
unordered_map<int, int> cnt;
unordered_map<int, vector<int> > ans;
pair<int, int> s[200005];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    FOR (i, 1, n) {
        cin >> p[i];
        cnt[p[i]]++;
    }
    FOR (i, 1, m) {
        cin >> tmp;
        s[i] = {tmp, i};
    }
    sort(s + 1, s + m + 1);
    int c = 0, u = 0;
    FOR (i, 1, m)
    {
        int val = s[i].first;
        int ind = s[i].second;
        int cur = 0;
        while (1)
        {
            if (cnt.count(val) && cnt[val])
            {
                c++;
                u += cur;
                cnt[val]--;
                ans[val].pb(ind);
                soc[ind] = cur;
                break;
            }
            if ((val + 1) / 2 == val) break;
            val = (val + 1) / 2;
            cur++;
        }
    }
    cout << c << ' ' << u << endl;
    FOR (i, 1, m) cout << soc[i] << ' ';
    cout << endl;
    FOR (i, 1, n)
    {
        int val = p[i];
        if (ans.count(val) && ans[val].size())
        {
            cout << ans[val].back() << ' ';
            ans[val].pop_back();
        }
        else cout << 0 << ' ';
    }
}