#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long kb[c], kj[c], t[c][2], jobb, bal, mini=2e9, maxi, n, m, k, w, x, y, z;
bool v[c];
long long dist(long long a, long long b)
{
    long long x=2e9;
    if (kb[a]) {
        x=abs(a-kb[a])+abs(b-kb[a]);
    }
    if (kj[a]) {
        x=min(x, abs(kj[a]-a)+abs(kj[a]-b));
    }
    return x;
}
int main()
{
    cin >> n >> m >> k >> w;
    for (long long i=1; i<=k; i++) {
        long long a, b;
        cin >> a >> b;
        if (!t[a][0]) {
            t[a][0]=b;
        }
        t[a][0]=min(t[a][0], b);
        t[a][1]=max(t[a][1], b);
        maxi=max(maxi, a);
        mini=min(mini, a);
    }
    for (long long i=1; i<=w; i++) {
        long long x;
        cin >> x;
        v[x]=true;
    }
    long long akt=0;
    for (long long i=1; i<=m; i++) {
        if (v[i]) {
            akt=i;
        }
        kb[i]=akt;
    }
    akt=0;
    for (long long i=m; i>=1; i--) {
        if (v[i]) {
            akt=i;
        }
        kj[i]=akt;
    }
    jobb=t[maxi][1]-t[maxi][0];
    bal=jobb;
    x=t[maxi][0];
    y=t[maxi][1];
    for (long long i=maxi-1; i>=mini; i--) {
        if (t[i][0]) {
            long long c=t[i][1]-t[i][0];
            long long a=min(c+dist(t[i][1], x)+bal, c+dist(t[i][1], y)+jobb);
            long long b=min(c+dist(t[i][0], x)+bal, c+dist(t[i][0], y)+jobb);
            bal=a, jobb=b;
            x=t[i][0];
            y=t[i][1];
        }
    }
    if (mini!=1) {
        bal+=dist(1, x);
        jobb+=dist(1, y);
    } else {
        bal+=t[1][0]-1;
        jobb+=t[1][1]-1;
    }
    cout << min(bal, jobb)+maxi-1;
    return 0;
}