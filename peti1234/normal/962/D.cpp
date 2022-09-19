#include <bits/stdc++.h>

using namespace std;
long long n, ans[150002], elh, elert, cnt;
priority_queue<pair<long long, int> > q;
void add(long long a, int b) {
    q.push({-a, -b});
}
void valt(int a, long long b) {
    if (a) {
        cnt++;
        ans[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        add(x, i);
    }
    while (q.size()>0) {
        long long ert=-q.top().first, pos=-q.top().second;
        q.pop();
        if (ert!=elert) {
            valt(elh, elert);
            elh=pos, elert=ert;
        } else {
            add(2*ert, pos);
            elh=0, elert=0;
        }
    }
    valt(elh, elert);
    cout << cnt << "\n";
    for (int i=1; i<=n; i++) {
        if (ans[i]) {
            cout << ans[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}