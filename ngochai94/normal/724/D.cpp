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

int m, chosen[100005];
int lis[100005];
string s;
vector<char> ans;
set<pair<char, int> > tot;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> m >> s;
    REP (i, m) tot.insert({s[i], -i});
    lis[0] = -(tot.begin()->second);
    //cout << lis[0] << endl;
    FOR (i, 1, s.size() - 1)
    {
        tot.erase({s[i - 1], -i + 1});
        if (i + m - 1 < s.size()) tot.insert({s[i + m - 1], - i - m + 1});
        lis[i] = -(tot.begin()->second);
        //cout << i << ' ' << lis[i] << endl;
    }
    int cur = 0;
    //int cnt = 0;
    char worst = 'a';
    while (cur < s.size() - m + 1)
    {
        //BUG(cur);
        ans.pb(s[lis[cur]]);
        chosen[lis[cur]] = 1;
        worst = max(worst, s[lis[cur]]);
        cur = lis[cur] + 1;
    }
    //for (auto c: ans) cout << c; cout << endl;
    //FOR (i, cur, s.size() - 1) if (s[i] < worst) ans.pb(s[i]);
    REP (i, s.size()) if (!chosen[i] && s[i] < worst) ans.pb(s[i]);
    sort(ans.begin(), ans.end());
    for (char c: ans) cout << c;
}