#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int n, el;
bool pr[c], v[c];
int kio[c], kp[c];
priority_queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            kio[i]=i;
            for (int j=2*i; j<=n; j+=i) if (!pr[j]) pr[j]=true, kio[j]=i;
        }
    }
    for (int i=n; i>=1; i--) {
        kp[i]=el;
        if (!pr[i]) el=i;
    }
    kio[1]=1, q.push({-1, 1});
    while(q.size()>0) {
        int er=-q.top().first, szam=q.top().second;
        q.pop();
        if (!v[szam]) {
            v[szam]=true;
            if (szam!=1) cout << er << " ";
            int x=kio[szam], y=kp[x], z=szam/x*y;
            if (szam/x*y<=n && y && (y<=kio[szam/x] || !pr[szam])) q.push({-er, z});
            if (2*szam<=n) q.push({-szam, 2*szam});
        }
    }
    return 0;
}
// Nem ez a legegyszerbb megolds, bonyolultabb adatszerkezeteknl rdemes tgondolni, hogy mit csinl, s tnyleg szgsg van r.