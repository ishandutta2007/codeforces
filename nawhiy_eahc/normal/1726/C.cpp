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

string s;

void solve()
{
    int n; cin >> n;
    cin >> s;
    int ans = n;
    for(int i=1;i<2*n;i++)
    {
        if(s[i-1] == ')' && s[i] == '(') ans--;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}