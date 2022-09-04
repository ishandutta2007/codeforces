#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const ld EPS = 1e-9;

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int a[maxn], b[maxn], p[maxn];

multiset<pair<int, pair<int, int> > > q[3];

int n;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	    #ifndef STR
	    //ifstream cin("a.in");
	    //ofstream cout("a.out");
	    //freopen("a.in", "r", stdin);
	    //freopen("a.out", "w", stdout);
    	    #endif // STR
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--, q[a[i]].insert(make_pair(p[i], make_pair(i, 0)));
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i]--, q[b[i]].insert(make_pair(p[i], make_pair(i, 1)));
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        x--;
        if (q[x].empty())
            cout << -1 << ' ';
        else{
            int v = q[x].begin()->second.first;
            cout << q[x].begin()->first << ' ';
            q[a[v]].erase(q[a[v]].find(make_pair(p[v], make_pair(v, 0))));
            q[b[v]].erase(q[b[v]].find(make_pair(p[v], make_pair(v, 1))));
        }
    }
}