#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int e[c], t[c], db[c], r[c], n, q;
int solve(int s, int f)
{
    int maxi=0;
    for (int i=s; i<=f; i++) {
        maxi=max(maxi, db[t[i]]);
    }
    return f-s+1-maxi;
}
int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        r[i]=i;
        int x;
        cin >> x;
        t[i]=x;
        db[x]++;
        if (db[x]==1) {
            e[x]=i;
        } else {
            r[e[x]]=i;
        }
    }
    for (int i=2; i<=n; i++) {
        r[i]=max(r[i-1], r[i]);
    }
    for (int i=n; i>=1; i--) {
        if (r[i]>=i+1) {
            r[i]=max(r[i], r[i+1]);
        }
    }
    int ans=0;
    for (int i=1; i<=n; i=r[i]+1) {
        ans+=solve(i, r[i]);
    }
    cout << ans << "\n";
    return 0;
}