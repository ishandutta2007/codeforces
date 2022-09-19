#include <bits/stdc++.h>

using namespace std;
long long w, n;
long long l, r;
vector<pair<long long, long long> > sz;
vector<pair<long long, long long> > sol;
int main()
{
    ios_base::sync_with_stdio(false), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> l >> r;
        sz.clear(), sol.clear(), sz.push_back({0, 1});
        for (long long i=1; i<n; i++) {
            long long x=sz.back().first, y=x+2*n-2*i, z=i;
            if (r>x && l<=y) {
                for (long long j=1; j<=2*(n-i); j++) {
                    if (j%2==0) sol.push_back({x+j, z+j/2});
                    else sol.push_back({x+j, z});
                }
            }
            sz.push_back({y, z});
        }
        for (long long i=0; i<sol.size(); i++) {
            long long fi=sol[i].first, se=sol[i].second;
            if (l<=fi && fi<=r) cout << se << " ";
        }
        if (r==n*(n-1)+1) cout << 1;
        cout << "\n";
    }
    return 0;
}
// Gusztustalan feladat, de viszonylag gyorsan megvolt.