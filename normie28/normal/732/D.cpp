#include <bits/stdc++.h>
using namespace std;
int s[200000], a[200000], t[200000], m;
bool ok (int x)
{
    for (int i = 1; i <= m; i++) s[i] = 0;
    while (a[x] == 0 && x) x--;
    int p = 0;
    while(x){
        if (a[x] != 0 && s[a[x]] == 0) {
            s[a[x]] = 1;
            p += t[a[x]];
        } else p = max(0, p - 1);
        x--;
    }
    for (int i = 1; i <= m; i++) if (s[i] == 0) return 0;
    if (p == 0) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=m; i++) cin>>t[i];
    int l = 2, r = n;
    if (!ok(r)){
        cout << -1;
        return 0;
    }
    while (r - l > 10)
    {
        int mid = (r + l)/2;
        if (ok(mid)) r = mid; else l = mid + 1;
    }
    while(!ok(l)) {
        l++;
    }
    while (a[l] == 0) l++;
    cout<<l;
}