#include <bits/stdc++.h>

using namespace std;
const int c=500002;
long long n, k, f, cnt;
long double ans;
vector<long double> sz[c], sor;
map<pair<int, int>, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    f=k/2;
    for (int i=1; i<=n; i++) {
        long long x, y, s;
        cin >> x >> y;
        if (x==0 && y==0) {
            continue;
        }
        s=abs(__gcd(x, y));
        long double dist=sqrt(x*x+y*y);
        x/=s, y/=s;
        if (!m[{x, y}]) {
            m[{x, y}]=++cnt;
        }
        sz[m[{x, y}]].push_back(dist);
    }
    sor.push_back(0);
    for (int i=1; i<=cnt; i++) {
        sort(sz[i].begin(), sz[i].end());
        int si=sz[i].size();
        long double sp=0;
        for (int j=1; j<=si; j++) {
            if (j<=f) {
                sor.push_back(sz[i][si-j]*(k+1-2*j));
            } else {
                sor.push_back(sz[i][j-f-1]*(k-1-2*f)-2*sp);
                sp+=sz[i][j-f-1];
            }
        }
    }
    sort(sor.rbegin(), sor.rend());
    for (int i=0; i<k; i++) {
        ans+=sor[i];
    }
    cout.precision(20);
    cout << ans << "\n";
    return 0;
}