#include <bits/stdc++.h>

using namespace std;
int w, n, ans[200002];
priority_queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        q.push({n-1, -1});
        for (int i=1; i<=n; i++) {
            int k=-q.top().second, l=q.top().first, v=k+l, m=(k+v)/2;
            //cout << k << " " << v << " " << m << "\n";
            q.pop(), ans[m]=i;
            if (m-1>=k) q.push({m-1-k,-k});
            if (m+1<=v) q.push({v-m-1, -m-1});
        }
        for (int i=1; i<=n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}