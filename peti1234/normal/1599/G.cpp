#include <bits/stdc++.h>

using namespace std;
long long n, id, ut;
pair<long long, long long> st;
vector<pair<long long, long long> > sz;
long long sq(long long x) {
    return x*x;
}
long double dist(int a, int b) {
    long double ert=sq(sz[a].first-sz[b].first)+sq(sz[a].second-sz[b].second);
    return sqrt(ert);
}
long double calc(int a, int b) {
    if (a>b) {
        return 0.0;
    }
    return dist(a, b)+min(dist(ut, a), dist(ut, b));
}
bool jo(int a, int b, int c) {
    long long s=(sz[b].first-sz[a].first)*(sz[c].second-sz[a].second)-(sz[b].second-sz[a].second)*(sz[c].first-sz[a].first);
    return (s==0);
}
int main()
{
    cin >> n >> id;
    ut=n-1;
    cout.precision(20);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        sz.push_back({x, y});
    }
    st=sz[id-1];
    if (n==3) {
        id--;
        int a=(id==0 ? 1 : id-1), b=3-a-id;
        cout << min(dist(id, a)+dist(a, b), dist(id, b)+dist(b, a)) << "\n";
        return 0;
    }
    if (jo(0, 1, 2)) {
        for (int i=3; i<n; i++) {
            if (!jo(0, 1, i)) {
                swap(sz[i], sz[ut]);
            }
        }
    } else {
        if (jo(0, 1, 3)) {
            swap(sz[2], sz[ut]);
        } else if (jo(0, 2, 3)) {
            swap(sz[1], sz[ut]);
        } else {
            swap(sz[0], sz[ut]);
        }
    }
    sort(sz.begin(), sz.begin()+n-1);
    if (st==sz[ut]) {
        cout << calc(0, n-2) << "\n";
    } else {
        long double ans=1e18;
        for (int pos=0; pos<n-1; pos++) {
            if (sz[pos]==st) {
                ans=min({ans, dist(pos, ut)+calc(0, n-2), dist(pos, 0)+dist(0, ut)+calc(pos+1, n-2), dist(pos, n-2)+dist(n-2, ut)+calc(0, pos-1)});
                ans=min({ans, dist(pos, 0)+dist(0, n-2)+dist(n-2, ut), dist(pos, n-2)+dist(n-2, 0)+dist(0, ut)});
                for (int kezd=0; kezd<n-2; kezd++) {
                    ans=min(ans, dist(pos, 0)+dist(0, kezd)+dist(kezd, ut)+calc(kezd+1, n-2));
                    ans=min(ans, dist(pos, n-2)+dist(n-2, kezd+1)+dist(kezd+1, ut)+calc(0, kezd));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}