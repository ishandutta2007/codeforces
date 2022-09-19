#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, t[c], pos[c], inv[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=0; i<=n; i++) pos[i]=i, inv[i]=i;
    for (int i=1; i<=n; i++) {
        int a=i, b=pos[t[i]], c=inv[a], d=inv[b];
        swap(inv[a], inv[b]), swap(pos[c], pos[d]);
    }
    for (int i=0; i<n; i++) cout << inv[i] << " ";
    return 0;
}