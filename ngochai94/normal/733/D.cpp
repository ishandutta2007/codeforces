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

struct rec {
    long long side;
    int ind;
    rec(long long aa, int ab) : side(aa), ind(ab) {}
    rec(): side(0), ind(0) {}
};

long long n, a, b, c, largest;
map<pair<long long, long long>, pair<rec, rec> > m;
pair<int, int> ans;

void adding(long long x, long long y, rec tmp)
{
    if (m.count({x, y}) == 0)
    {
        m[{x, y}] = {rec(), tmp};
    }
    else if (tmp.side > m[{x, y}].second.side)
    {
        m[{x, y}].first = m[{x, y}].second;
        m[{x, y}].second = tmp;
    }
    else if (tmp.side > m[{x, y}].first.side)
    {
        m[{x, y}].first = tmp;
    }
}

void add(int ind)
{
    if (a == b == c)
    {
        adding(a, a, rec(a, ind));
    }
    else if (a == b)
    {
        adding(a, a, rec(c, ind));
        adding(a, c, rec(a, ind));
    }
    else if (a == c)
    {
        adding(a, a, rec(b, ind));
        adding(a, b, rec(a, ind));
    }
    else if (b == c)
    {
        adding(b, b, rec(a, ind));
        adding(a, b, rec(b, ind));
    }
    else
    {
        adding(a, b, rec(c, ind));
        adding(a, c, rec(b, ind));
        adding(b, c, rec(a, ind));
    }
}

long long ll[3];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n)
    {
        REP (j, 3) cin >> ll[j];
        sort(ll, ll + 3);
        a = ll[0];
        b = ll[1];
        c = ll[2];
        if (largest < a)
        {
            largest = a;
            ans = {-1, i + 1};
        }
        add(i + 1);
    }
    for (auto it: m)
    {
        a = it.first.first;
        b = it.first.second;
        c = it.second.first.side + it.second.second.side;
        if (largest < min(a, min(b, c)))
        {
            largest = min(a, min(b, c));
            ans = {it.second.first.ind, it.second.second.ind};
        }
    }
    if (ans.first == -1) cout << 1 << endl << ans.second;
    else cout << 2 << endl << ans.first << ' ' << ans.second;
}