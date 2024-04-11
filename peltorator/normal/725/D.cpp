#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const int inf = 2e9;
const ll infl = 3e18;

multiset<ll> s;
vector< pair<ll, ll> > v;
ll cur, best, pos;

int main()
{
    int n;
    cin >> n;
    pos = 1, best = infl;
    ll tmp;
    cin >> cur >> tmp;
    for (int i = 0; i < n - 1; i++)
    {
        ll t, w;
        cin >> t >> w;
        v.push_back({t, w - t + 1});
    }
    sort(v.begin(), v.end());
    while (!v.empty() && v[v.size() - 1].first > cur)
    {
        s.insert(v[v.size() - 1].second);
        v.pop_back();
        pos++;
    }
    best = min(best, pos);
    while (!s.empty()) {
        ll x = *s.begin();
        s.erase(s.begin());
        if (cur < x)
            break;
        cur -= x;
        pos--;
        while (!v.empty() && v[v.size() - 1].first > cur)
        {
            s.insert(v[v.size() - 1].second);
            v.pop_back();
            pos++;
        }
        best = min(best, pos);
    }
    cout << best;
}