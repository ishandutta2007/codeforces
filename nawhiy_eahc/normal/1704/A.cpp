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

void solve()
{
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    bool flag = true;
    for(int j=0;j<m-1;j++)
    {
        if(t[m-j-1] != s[n-j-1]) flag = false;
    }
    
    bool flag2 = false;
    for(int i=0;i<=n-m;i++)
    {
        if(t[0] == s[i]) flag2 = true;
    }
    
    if(flag & flag2) cout << "YES\n";
    else cout << "NO\n";
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