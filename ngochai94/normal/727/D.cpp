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

int lis[6], n;
string ans[100005], s, ts[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
vector<int> v[5];
map<string, int> lookup;

bool prefix(string s, string ss)
{
    return s.substr(0, ss.size()) == ss;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    REP (i, 6) lookup[ts[i]] = i;
    REP (i, 6) cin >> lis[i];
    cin >> n;
    REP (i, n)
    {
        cin >> s;
        bool flag = false;
        for (char c: s) if (c == ',') flag = true;
        if (!flag)
        {
            int ind = lookup[s];
            lis[ind]--;
            ans[i] = s;
        }
        else
        {
            REP (j, 5) if (prefix(s, ts[j]))
            {
                v[j].pb(i);
                break;
            }
        }
    }
    REP (i, 6) if (lis[i] < 0)
    {
        cout << "NO";
        return 0;
    }
    REP (i, 5)
    {
        if (lis[i] + lis[i + 1] < v[i].size())
        {
            cout << "NO";
            return 0;
        }
        int tmp = min(lis[i], (int)v[i].size());
        REP (j, tmp)
        {
            lis[i]--;
            ans[v[i].back()] = ts[i];
            v[i].pop_back();
        }
        tmp = min(lis[i + 1], (int)v[i].size());
        REP (j, tmp)
        {
            lis[i + 1]--;
            ans[v[i].back()] = ts[i + 1];
            v[i].pop_back();
        }
    }
    cout << "YES" << endl;
    REP (i, n) cout << ans[i] << endl;
}