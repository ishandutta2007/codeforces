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

long long n, lis[555], m, val;
vector<pair<int, char> > v;
vector<long long> que;
vector<pair<long long, int> > sor;
vector<long long> tmp;

void eatLeft(int x)
{
    tmp.clear();
    REP (i, x - 1) tmp.pb(que[i]);
    tmp.pb(que[x] + que[x - 1]);
    FOR (i, x + 1, que.size() - 1) tmp.pb(que[i]);
    que.clear();
    for (auto i: tmp) que.pb(i);
}

void eatRight(int x)
{
    tmp.clear();
    REP (i, x) tmp.pb(que[i]);
    tmp.pb(que[x] + que[x + 1]);
    FOR (i, x + 2, que.size() - 1) tmp.pb(que[i]);
    que.clear();
    for (auto i: tmp) que.pb(i);
}

bool solve(int add)
{
    while (que.size() > 1)
    {
        int len = que.size();
        sor.clear();
        REP (i, len) sor.pb({que[i], i});
        sort(sor.begin(), sor.end());
        //for (auto it: sor)
        reverse(sor.begin(), sor.end());
        //if (que.size() == 5) for (auto p: sor) cout << p.first << ' ' << p.second << endl;
        bool flag = false;
        for (auto p: sor)
        {
            long long lef = 0;
            long long rig = 0;
            if (p.second) lef = p.first - que[p.second - 1];
            if (p.second < len - 1) rig = p.first - que[p.second + 1];
            if (lef >= rig && lef > 0)
            {
                flag = true;
                eatLeft(p.second);
                v.pb({p.second + add, 'L'});
                break;
            }
            if (lef <= rig && rig > 0)
            {
                flag = true;
                eatRight(p.second);
                v.pb({p.second + add, 'R'});
                break;
            }
            if (flag) break;
        }
        if (!flag) return false;
    }
    return true;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    cin >> m;
    int pt = 0;
    REP (i, m)
    {
        que.clear();
        cin >> val;
        //BUG(val);
        long long cur = 0;
        while (cur < val && pt < n)
        {
            cur += lis[pt];
            que.pb(lis[pt++]);
        }
        //BUG(pt);
        if (cur != val)
        {
            cout << "NO";
            return 0;
        }
        bool can = solve(i + 1);
        if (!can)
        {
            cout << "NO";
            return 0;
        }
    }
    if (pt != n) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (auto p: v) cout << p.first << ' ' << p.second << endl;
}