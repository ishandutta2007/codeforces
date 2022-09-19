#include <bits/stdc++.h>

using namespace std;
long long n, m, p, maxi=-INT_MAX;
vector<pair<long long, long long> > a, b;
vector<pair<long long, long long> > sz[200001];
long long c=262144;
long long t[600001], s[600001], f[600001], l[600001];
long long ask(long long a, long long k, long long v)
{
    long long x=s[a];
    long long y=f[a];
    if (k>y || x>v) {
        return -INT_MAX;
    }
    if (k<=x && y<=v) {
        return t[a]+l[a];
    }
    l[2*a]+=l[a];
    l[2*a+1]+=l[a];
    l[a]=0;
    return max(ask(2*a, k, v), ask(2*a+1, k, v));
}
void change(long long a, long long k, long long v, long long e)
{
    long long x=s[a];
    long long y=f[a];
    if (k>y || x>v) {
        return;
    }
    if (k<=x && y<=v) {
        l[a]+=e;
        return;
    }
    change(2*a, k, v, e);
    change(2*a+1, k, v, e);
    t[a]=max(t[2*a]+l[2*a], t[2*a+1]+l[2*a+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (long long i=c; i<=2*c; i++) {
        s[i]=i;
        f[i]=i;
    }
    for (long long i=c-1; i>=1; i--) {
        s[i]=s[2*i];
        f[i]=f[2*i+1];
        t[i]=t[2*i]+t[2*i+1];
    }
    cin >> n >> m >> p;
    for (long long i=1; i<=n; i++) {
        long long x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    for (long long i=1; i<=m; i++) {
        long long x, y;
        cin >> x >> y;
        b.push_back({x, y});
    }
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    for (long long i=1; i<=p; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        long long lo=-1, up=n-1;
        if (x>=a[n-1].first) continue;
        while (up-lo>1) {
            long long mid=(up+lo)/2;
            if (x>=a[mid].first) lo=mid;
            else up=mid;
        }
        sz[up].push_back({y, z});
    }
    for (long long i=n-1; i>=1; i--) a[i].second-=a[i-1].second;
    for (long long i=m-1; i>=1; i--) b[i].second-=b[i-1].second;
    for (long long i=0; i<m; i++) change(1, i+c, 2*c-1, -b[i].second);
    for (long long i=0; i<n; i++) {
        change(1, c, 2*c-1, -a[i].second);
        for (long long j=0; j<sz[i].size(); j++) {
            long long lo=-1, up=m-1, x=sz[i][j].first;
            if (x>=b[up].first) continue;
            while(up-lo>1) {
                long long mid=(up+lo)/2;
                if (x>=b[mid].first) lo=mid;
                else up=mid;
            }
            change(1, up+c, 2*c-1, sz[i][j].second);
        }
        maxi=max(maxi, ask(1, c, 2*c-1));
    }
    cout << maxi << "\n";
    return 0;
}