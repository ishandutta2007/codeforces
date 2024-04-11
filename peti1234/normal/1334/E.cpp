#include <bits/stdc++.h>

using namespace std;
long long n, d, q, a, b, c, mod=998244353;
vector<pair<long long, long long> > sol;
vector<long long> pr;
priority_queue<pair<long long, long long> >p;
long long gcd(long long a, long long b) {
    if (a>b) swap(a, b);
    if (a==0) return b;
    return gcd(a, b%a);
}
long long ker(long long a) {
    long long x=-1, y=sol.size();
    while(y-x>1) {
        long long z=(x+y)/2, fi=sol[z].first, se=sol[z].second;
        if (a==fi) return se;
        if (a>fi) x=z;
        else y=z;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q, d=n;
    for (long long i=2; i*i<=d; i++) {
        if (d%i==0) {
            pr.push_back(i);
            while(d%i==0) d/=i;
        }
    }
    if (d!=1) pr.push_back(d);
    p.push({-1, 1});
    while(p.size()>0) {
        long long fi=p.top().first, ert=0, x=n/(-fi);
        while(p.size()>0 && p.top().first==fi) ert+=p.top().second, p.pop();
        sol.push_back({-fi, ert});
        for (long long i=0; i<pr.size(); i++) if (x%pr[i]==0) p.push({fi*pr[i], ert});
    }
    for (long long i=1; i<=q; i++) {
        cin >> a >> b, c=gcd(a, b);
        a/=c, b/=c;
        cout << ker(a)*ker(b)%mod << "\n";
    }
    return 0;
}
// A megolds utn lassan talltam ki, hogy hogyan kne lerni.