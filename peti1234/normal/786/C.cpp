#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int t[c], ans[c], h[c], sz[c], n;
void ch(int a) {
    int db=0, cnt=0, si=0;
    for (int i=1; i<=n; i++) if (!h[t[i]]) {
        if (db==a) {
            cnt++, db=0;
            for (int i=1; i<=si; i++) h[sz[i]]=0;
            si=0;
        }
        db++, si++, sz[si]=t[i], h[t[i]]++;
    }
    for (int i=1; i<=si; i++) h[sz[i]]=0;
    if (db) cnt++;
    ans[a]=cnt;
}
void solve(int a, int b) {
    if (ans[a]==ans[b]) for (int i=a+1; i<b; i++) ans[i]=ans[a];
    else if (a<b-1) {
        int c=(a+b)/2;
        ch(c), solve(a, c), solve(c, b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    ch(1), ch(n), solve(1, n);
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}