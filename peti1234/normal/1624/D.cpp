#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, k;
        cin >> n >> k;
        map<char, int> m;
        string s;
        cin >> s;
        for (auto x:s) {
            m[x]++;
        }
        int par=0;
        for (auto x:m) {
            par+=(x.second)/2;
        }
        int ans=par/k*2;
        if (k*(ans+1)<=n) ans++;
        cout << ans << "\n";
    }
    return 0;
}