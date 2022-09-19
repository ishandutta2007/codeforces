#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, f, s, t, p, ans, s1[c], s2[c];
vector<pair<int, int> > e, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> f >> s >> t >> p, ans=n*t;
    e.push_back({t, 0});
    for (int i=1; i<=f; i++) cin >> s1[i];
    for (int i=1; i<=f; i++) cin >> s2[i];
    for (int i=1; i<=f; i++) e.push_back({s1[i], s2[i]});
    m.push_back({0, 0});
    for (int i=1; i<=s; i++) cin >> s1[i];// s1[i]=min(n, s1[i]);
    for (int i=1; i<=s; i++) cin >> s2[i];
    for (int i=1; i<=s; i++) m.push_back({s1[i], s2[i]});
    for (int i=0; i<=f; i++) {
        long long fi=e[i].first, se=e[i].second, lo=0, hi=s+1, mid;
        while(hi-lo>1) {
            mid=(hi+lo)/2;
            if (se+m[mid].second<=p) lo=mid;
            else hi=mid;
        }
        if (se<=p) ans=min(ans, (n-m[lo].first)*fi);
    }
    cout << ans << "\n";
    return 0;
}