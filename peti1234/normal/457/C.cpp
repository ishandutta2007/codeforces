#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, sum, cnt, pos, mini;
priority_queue<int> q;
vector<int> sz[c];
vector<pair<int, int> > s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cnt=n;
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        if (a) {
            sum+=b;
            sz[a].push_back(b);
        }
    }
    for (int i=1; i<c; i++) {
        sort(sz[i].rbegin(), sz[i].rend());
        for (int j=0; j<sz[i].size(); j++) {
            s.push_back({j+1, sz[i][j]});
        }
    }
    mini=sum;
    sort(s.begin(), s.end());
    for (int i=1; i<=n; i++) {
        while (pos<s.size() && s[pos].first==i) {
            cnt--;
            int ert=s[pos].second;
            sum-=ert;
            q.push(-ert);
            pos++;
        }
        while (q.size()>0 && cnt<=i) {
            sum-=q.top();
            cnt++;
            q.pop();
        }
        if (cnt>i) {
            mini=min(mini, sum);
        }
    }
    cout << mini << "\n";
    return 0;
}