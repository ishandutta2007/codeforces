#include <bits/stdc++.h>

using namespace std;
long long x, y, l, r, maxi, si;
vector<long long> sz;
long long mul(long long a, long long b) {
    long double p=log(a)+log(b);
    if (p>42) return r+1;
    return a*b;
}
long long po(long long a, long long b) {
    long long ans=1;
    for (int i=1; i<=b; i++) {
        ans=mul(ans, a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> l >> r;
    sz.push_back(l-1), sz.push_back(r+1);
    for (int i=0; i<=60; i++) {
        for (int j=0; j<=60; j++) {
            long long s=po(x, i), t=po(y, j), k=s+t;
            if (l<=k && k<=r) sz.push_back(k);
        }
    }
    sort(sz.begin(), sz.end());
    si=sz.size();
    for (int i=1; i<si; i++) {
        maxi=max(maxi, sz[i]-sz[i-1]);
    }
    cout << maxi-1 << "\n";
    return 0;
}