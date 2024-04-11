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
int b[200000];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++) cin >> a[i];
    sort(a, a+m);
    
    for(int i=0;i<m-1;i++) b[i] = a[i+1] - a[i] - 1;
    b[m-1] = n - a[m-1] + a[0] - 1;
    
    sort(b, b+m);
    int t = 0;
    int infect = m;
    for(int i=m-1;i>=0;i--)
    {
        int now = max(0, b[i] - 2 * t);
        if(now > 0)
        {
            if(now == 1) infect += b[i] - 1;
            else if(now == 2) infect += b[i] - 1;
            else infect += 2 * t + 1;
            t += 2;
        }
        else infect += b[i];
    }
    cout << infect << "\n";
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