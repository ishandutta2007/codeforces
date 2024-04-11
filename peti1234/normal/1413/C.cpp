#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=6;
long long s[7], n, ans=1e9, mini=1e9, t[c];
priority_queue<pair<int, pair<int, int> > > q;
void pb(int a, int b) {
    q.push({t[a]-s[b], {a, b}});
    mini=min(mini, t[a]-s[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<=k; i++) cin >> s[i];
    sort(s+1, s+7);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pb(i, 1);
    }
    while(true) {
        long long f=q.top().first, id=q.top().second.first, pos=q.top().second.second;
        q.pop();
        ans=min(ans, f-mini);
        if (pos==k) {
            break;
        }
        pb(id, pos+1);
    }
    cout << ans << "\n";
    return 0;
}