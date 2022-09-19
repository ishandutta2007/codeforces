#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long sum, a[c], b[c], si[c], ans[c], s=1, f, n;
queue<int> q;
int main()
{
    cin >> n, f=n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        if (b[i]>0) si[b[i]]++;
    }
    for (int i=1; i<=n; i++) if (!si[i]) q.push(i);
    while(q.size()>0) {
        int x=q.front();
        q.pop();
        sum+=a[x];
        if (b[x]>0) {
            if (a[x]>0) a[b[x]]+=a[x], ans[s]=x, s++;
            else ans[f]=x, f--;
            si[b[x]]--;
            if (si[b[x]]==0) q.push(b[x]);
        } else ans[s]=x, s++;
    }
    cout << sum << "\n";
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}