#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, n, m, x, t[c];
priority_queue<pair<long long, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> x;
        while (q.size()>0) {
            q.pop();
        }
        for (int i=1; i<=m; i++) {
            t[i]=0;
            q.push({-t[i], i});
        }
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            int a;
            cin >> a;
            int id=q.top().second;
            cout << id << " ";
            q.pop();
            t[id]+=a;
            q.push({-t[id], id});
        }
        cout << "\n";
    }
    return 0;
}