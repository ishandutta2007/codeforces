#include <bits/stdc++.h>

using namespace std;
long long n, sum, s[7005];
bool v[7005];
vector<pair<long long, long long> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<n; i++) {
        long long x;
        cin >> x;
        sz.push_back({s[i], x});
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<n; i++) {
        if (i!=n-1 && sz[i].first==sz[i+1].first) v[i]=1;
        for (int j=0; j<i; j++) if (v[j] && ((sz[j].first & sz[i].first)==sz[i].first)) v[i]=1;
        if (v[i]) sum+=sz[i].second;
    }
    cout << sum << "\n";
    return 0;
}