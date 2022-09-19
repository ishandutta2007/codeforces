#include <bits/stdc++.h>

using namespace std;
const int c=102;
int n, t[c], bal[c], jobb[c], s=(1<<15);
map<vector<int>, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        bal[i]=t[i]%s;
        jobb[i]=t[i]/s;
    }
    for (int i=0; i<s; i++) {
        vector<int> sz;
        for (int j=2; j<=n; j++) {
            sz.push_back(__builtin_popcount(bal[1]^i)-__builtin_popcount(bal[j]^i));
        }
        m[sz]=i;
    }
    for (int i=0; i<s; i++) {
        vector<int> sz;
        for (int j=2; j<=n; j++) {
            sz.push_back(__builtin_popcount(jobb[j]^i)-__builtin_popcount(jobb[1]^i));
        }
        if (m.find(sz)!=m.end()) {
            int x=m[sz], ans=x+i*s;
            cout << ans << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}