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

int a[200000];

void solve()
{
    int n, x; cin >> n >> x;
    for(int i=0;i<n;i++) cin >> a[i];
    
    int M = a[0], m = a[0];
    int cnt = 0;
    for(int i=1;i<n;i++)
    {
        M = max(M, a[i]);
        m = min(m, a[i]);
        
        if(M - m > 2 * x)
        {
            cnt++;
            M = a[i];
            m = a[i];
        }
    }
    cout << cnt << "\n";
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