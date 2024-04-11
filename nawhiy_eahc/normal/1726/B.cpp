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
    if(n > m) cout << "No\n";
    else if(n%2 == 0 && m%2 == 1) cout << "No\n";
    else if(n%2 == 1)
    {
        cout << "Yes\n";
        for(int i=1;i<n;i++) cout << "1 ";
        cout << m - n + 1 << "\n";
    }
    else
    {
        cout << "Yes\n";
        for(int i=1;i<n-1;i++) cout << "1 ";
        cout << (m-n+2)/2 << " " << (m-n+2)/2 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}