#include <bits/stdc++.h>

using namespace std;
int n, k, db, si;
bool pr[1002];
vector<int> sz;
int main()
{
    cin >> n >> k;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            sz.push_back(i);
            for (int j=2*i; j<=n; j+=i) pr[j]=1;
        }
    }
    si=sz.size();
    for (int i=1; i<si; i++) {
        int x=sz[i-1]+sz[i]+1;
        if (x<=n && !pr[x]) db++;
    }
    if (db>=k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}