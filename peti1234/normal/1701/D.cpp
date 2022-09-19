#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long w, n, ans[c];
vector<pair<int, int> > sz[c];
priority_queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            long long kis=0, nagy=0;
            kis=i/(x+1)+1;
            nagy=(x==0 ? n : i/x);
            //cout << i << " " << kis << " " << nagy << "\n";
            sz[kis].push_back({-nagy, i});
        }
        for (int i=1; i<=n; i++) {
            for (auto x:sz[i]) {
                q.push(x);
            }
            ans[q.top().second]=i;
            q.pop();
            sz[i].clear();
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
1
5
0 0 1 4 1
*/