#include <bits/stdc++.h>

using namespace std;
#define lsb(i) ((i) & -(i))
long long n, sum, db, res;
long long h[200001], s[200001], hova[200001], fert[200001], fdb[200001];
vector<pair<long long, long long> > v, sz, ren;

void add(long long a, long long b) {
    while(a<=n) fert[a]+=b, fdb[a]++, a+=lsb(a);
}
void ask(long long a) {
    sum=0, db=0;
    while(a>0) sum+=fert[a], db+=fdb[a], a-=lsb(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> h[i];
    for (long long i=1; i<=n; i++) cin >> s[i];
    for (long long i=1; i<=n; i++) ren.push_back({h[i], s[i]});
    sort(ren.begin(), ren.end());
    for (long long i=1; i<=n; i++) h[i]=ren[i-1].first, v.push_back({h[i], i});
    sort(v.begin(), v.end());
    for (long long i=0; i<n; i++) hova[v[i].second]=i+1;
    for (long long i=1; i<=n; i++) s[i]=ren[i-1].second, sz.push_back({s[i], i});
    sort(sz.begin(), sz.end());
    for (long long i=0; i<sz.size(); i++) {
        long long id=sz[i].second, hely=h[id], poz=hova[id];
        ask(poz);
        res+=db*hely-sum;
        add(poz, hely);
    }
    cout << res << "\n";
    return 0;
}