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

int a[2002];

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    if(n == 1)
    {
        cout << "0\n";
        return;
    }
    
    int Ma = 0, mi = 1000;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        Ma = max(Ma, a[i]);
        mi = min(mi, a[i]);
        ans = max(ans, a[i] - a[i%n+1]);
    }
    cout << max(max(a[n] - mi, Ma - a[1]), ans) << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}