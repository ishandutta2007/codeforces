#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> c[i][j];
    vector<ll> s(n);
    ll sm = INF, M = 0;
    for(int i=0;i<n;i++)
    {
        s[i] = 0;
        for(int j=0;j<m;j++) s[i] += j * c[i][j];
        sm = min(s[i], sm);
        M = max(s[i], M);
    }
    
    int id = -1;
    for(int i=0;i<n;i++) if(s[i] == M) id = i;
    
    cout << id+1 << " " << M-sm << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}