#include <bits/stdc++.h>

using namespace std;
const long long c=100002;
long long n, t[100002], ans=c*c;
vector<pair<long long, long long> > bal, jobb;
void ch(long long a, long long b) {
    if (b<=n) ans=min(ans, (a-b)*(a-b)+(t[a]-t[b])*(t[a]-t[b]));
}
long long solve(long long a, long long b) {
    if (a==b) return ans;
    long long c=(a+b)/2;
    ans=min({ans, solve(a, c), solve(c+1, b)});
    long long tav=sqrt(ans)+1, db=min(tav, c-a+1);
    bal.clear(), jobb.clear();
    for (long long i=c-db+1; i<=c; i++) bal.push_back({t[i], i});
    for (long long i=c+1; i<=c+db; i++) jobb.push_back({t[i], i});
    sort(bal.begin(), bal.end()), sort(jobb.begin(), jobb.end());
    long long x=0;
    for (long long i=0; i<db; i++) {
        long long fi=bal[i].first, se=bal[i].second;
        while(x<db && fi-jobb[x].first>=tav) x++;
        for (long long j=x; j<min(db, x+6); j++) ch(se, jobb[j].second);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        cin >> t[i];
        if (i>1) ans=min(ans, t[i]*t[i]+1), t[i]+=t[i-1];
    }
    cout << solve(1, n);
    return 0;
}