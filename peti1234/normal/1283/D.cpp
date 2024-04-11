#include <bits/stdc++.h>

using namespace std;
long long n, m, sum;
queue<pair<int, int> > q;
set<int> h;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        q.push({x-1, -1}), q.push({x+1, 1});
        h.insert(x);
    }
    while (ans.size()<m) {
        int id=q.front().first, ert=q.front().second;
        q.pop();
        if (h.find(id)==h.end()) {
            sum+=abs(ert);
            ans.push_back(id);
            h.insert(id);
            if (ert<0) {
                q.push({id-1, ert-1});
            } else {
                q.push({id+1, ert+1});
            }
        }
    }
    cout << sum << "\n";
    for (int x:ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}