#include <bits/stdc++.h>

using namespace std;
long long n, m, db[1000002], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {int a, b; cin >> a >> b, db[a]++, db[b]++;}
    for (int i=1; i<=n; i++) sum+=db[i]*(db[i]-1)+(n-1-db[i])*(n-2-db[i])-(db[i])*(n-1-db[i]);
    cout << sum/6 << "\n";
    return 0;
}