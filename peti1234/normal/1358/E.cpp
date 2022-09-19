#include <bits/stdc++.h>

using namespace std;
long long t[250002], sum, p, n, e, v, fix, x, db;
int pr(int x) {
    long long ans=db;
    for (int i=x; i>=1; i--) {
        ans+=t[i], ans-=p;
        if (ans<=0) return i;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, e=(n+1)/2, v=n-e, x=e;
    for (int i=1; i<=e; i++) cin >> t[i], sum+=t[i];
    cin >> p, sum+=v*p;
    if (p>=0) {
        if (sum>0) cout << n << "\n";
        else cout << -1 << "\n";
        return 0;
    }
    db=v*p;
    while(x>0) {
        while(db<=0 && x>=0) db+=t[x], x--;
        if (x<0) break;
        int y=pr(x);
        if (!y) {
            cout << n-x << "\n";
            return 0;
        }
        while(x>=y) db+=t[x], x--;
    }
    cout << -1 << "\n";
    return 0;
}