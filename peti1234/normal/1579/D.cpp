#include <bits/stdc++.h>

using namespace std;
int w, n;
priority_queue<pair<int, int> > q;
vector<pair<int, int> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            q.push({x, i});
        }
        while (true) {
            auto q1=q.top();
            q.pop();
            auto q2=q.top();
            q.pop();
            if (q1.first==0 || q2.first==0) {
                break;
            }
            ans.push_back({q1.second, q2.second});
            q1.first--, q2.first--;
            q.push(q1), q.push(q2);
        }
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }

        ans.clear();
        while (q.size()>0) {
            q.pop();
        }
    }
    return 0;
}