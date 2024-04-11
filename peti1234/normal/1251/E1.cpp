#include <bits/stdc++.h>

using namespace std;
int w, n;
long long sum, cnt;
vector<pair<int, int> > sz;
priority_queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int a, b;
            cin >> a >> b;
            sz.push_back({a, b});
        }
        sort(sz.begin(), sz.end());
        for (int i=n-1; i>=0; i--) {
            q.push(-sz[i].second);
            while (i+cnt<sz[i].first) {
                sum-=q.top();
                q.pop();
                cnt++;
            }
        }
        //cout << "valasz: ";
        cout << sum << "\n";
        sum=0, cnt=0;
        sz.clear();
        while (q.size()>0) {
            q.pop();
        }
    }
    return 0;
}