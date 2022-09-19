#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, qsum, ans, t[c];
vector<pair<int, int> > sz;
priority_queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sz.push_back({0, 0});
    sz.push_back({2e9, 0});
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back({t[i], x});
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<=n+1; i++) {

        int ert=sz[i].first-sz[i-1].first, se=sz[i].second;
        for (int j=1; j<=ert; j++) {
            if (q.size()>0) {
                qsum-=q.top();
                q.pop();
                ans+=qsum;
            } else {
                break;
            }
        }
        q.push(se);
        qsum+=se;
    }
    cout << ans << "\n";
    return 0;
}