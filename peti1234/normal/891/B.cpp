#include <bits/stdc++.h>

using namespace std;
int n, a[25], b[25];
vector<int> sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], sz.push_back(a[i]);
    sort(sz.begin(), sz.end()), sz.push_back(sz[0]);
    for (int i=1; i<=n; i++) for (int j=0; j<n; j++) if (a[i]==sz[j]) b[i]=sz[j+1];
    for (int i=1; i<=n; i++) cout << b[i] << " ";
    return 0;
}