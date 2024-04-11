#include <bits/stdc++.h>

using namespace std;
vector<pair<long long, long long> > sz;
priority_queue<long long> q;
long long db[200001];
long long sum, ans;
long long n, hol, p;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> db[i];
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        sz.push_back({db[i], x});
    }
    sort(sz.begin(), sz.end());
    while(p<n) {
        hol=sz[p].first;
        while(p<n && sz[p].first==hol) q.push(sz[p].second), sum+=sz[p].second, p++;
        while (q.size()>0) {
            sum-=q.top();
            ans+=sum;
            q.pop(), hol++;
            while(p<n && sz[p].first==hol) q.push(sz[p].second), sum+=sz[p].second, p++;
        }
    }
    cout << ans << endl;
    return 0;
}