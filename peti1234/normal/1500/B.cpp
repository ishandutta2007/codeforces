#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
long long n, m, k, a[c], b[c], ki[c], dist, ert, sum, kul, si, cnt=0;
vector<long long> tav[c], pos;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
    }
    if (n>m) {
        for (int i=1; i<=n; i++) {
            swap(a[i], b[i]);
        }
        swap(n, m);
    }
    for (int i=1; i<=n; i++) {
        ki[a[i]]=i;
    }
    for (int i=1; i<=m; i++) {
        int x=ki[b[i]];
        if (x) {
            tav[(i-x+m)%m].push_back(x);
        }
    }
    do {
        for (long long x:tav[dist]) {
            pos.push_back(ert+x);
        }
        ert+=n;
        dist=ert%m;
    } while (dist);
    si=pos.size();
    sort(pos.begin(), pos.end());
    kul=ert-si;
    sum=(k-1)/kul*ert, k-=(k-1)/kul*kul;
    if (k<1 || k>kul) {
        while (true) {

        }
    }
    pos.push_back(ert+1);
    for (long long i:pos) {
        long long dif=i-cnt-1;
        if (dif>=k) {
            cout << sum+cnt+k << "\n";
            return 0;
        }
        k-=dif;
        cnt=i;
    }
    return 0;
}