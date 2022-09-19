#include <bits/stdc++.h>

using namespace std;
const int c=200;
int w, n, mdb, maxi, si, ans;
int t[200002], db[202];
vector<int> p;
void add(int a) {
    db[t[a]]++, maxi=max(maxi, db[t[a]]);
}
void ch(int a) {
    for (int i=1; i<=c; i++) db[i]=0;
    maxi=0, p.clear();
    for (int i=1; i<=n; i++) if (t[i]==a) p.push_back(i);
    si=p.size();
    if (si<2) return;
    int x=si/2-1, y=(si+1)/2;
    for (int i=p[x]+1; i<p[y]; i++) add(i);
    ans=max(ans, 2*x+2+maxi);
    while(x>0) {
        for (int i=p[x-1]+1; i<p[x]; i++) add(i);
        for (int i=p[y]+1; i<p[y+1]; i++) add(i);
        x--, y++;
        ans=max(ans, 2*x+2+maxi);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        ans=1;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=c; i++) ch(i);
        cout << ans << "\n";
    }
    return 0;
}