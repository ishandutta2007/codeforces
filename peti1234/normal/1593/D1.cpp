#include <bits/stdc++.h>

using namespace std;
int w, n, ans;
vector<int> sz;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        for (int i=1; i<n; i++) {
            ans=__gcd(ans, abs(sz[i]-sz[0]));
        }
        cout << (ans==0 ? -1 : ans) << "\n";
        sz.clear();
        ans=0;
    }
    return 0;
}