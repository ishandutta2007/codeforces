#include <bits/stdc++.h>

using namespace std;
long long n, m, dif, res;
vector<long long> a, b;
vector<pair<long long, long long> > ans;
vector<pair<long long, pair<long long, long long> > > pa, pb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        dif+=x;
        a.push_back(x);
    }
    cin >> m;
    for (long long i=1; i<=m; i++) {
        long long x;
        cin >> x;
        dif-=x;
        b.push_back(x);
    }
    res=abs(dif);
    for (long long i=0; i<n; i++) {
        for (long long j=0; j<m; j++) {
            long long s=abs(dif+2*(b[j]-a[i]));
            if (s<res) {
                res=s;
                ans={{i+1, j+1}};
            }
        }
    }
    for (long long i=0; i<n; i++) {
        for (long long j=i+1; j<n; j++) {
            pa.push_back({a[i]+a[j], {i+1, j+1}});
        }
    }
    for (long long i=0; i<m; i++) {
        for (long long j=i+1; j<m; j++) {
            pb.push_back({b[i]+b[j], {i+1, j+1}});
        }
    }
    if (pb.size()>0) {
        sort(pa.begin(), pa.end());
        sort(pb.begin(), pb.end());
        long long pos=0, sb=pb.size();
        for (auto x:pa) {
            long long d=dif-2*x.first;
            while (pos+1<sb && abs(d+2*pb[pos].first)>=abs(d+2*pb[pos+1].first)) pos++;
            long long s=abs(d+2*pb[pos].first);
            if (s<res) {
                res=s;
                ans={{x.second.first, pb[pos].second.first}, {x.second.second, pb[pos].second.second}};
            }
        }
    }
    cout << res << "\n";
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}