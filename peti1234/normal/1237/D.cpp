#include <bits/stdc++.h>

using namespace std;
const int c=300005, sok=1e9;
int n, t[c], kov[c];
priority_queue<pair<int, int> > q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        t[i+n]=t[i];
        t[i+2*n]=t[i];
    }
    for (int i=1; i<=3*n; i++) {
        kov[i]=sok;
        int a=t[i];
        while(q.size()>0 && 2*a<q.top().first) {
            kov[q.top().second]=i;
            q.pop();
        }
        q.push({a, i});
    }
    for (int i=2*n; i>=1; i--) {
        kov[i]=min(kov[i], kov[i+1]);
    }
    for (int i=1; i<=n; i++) {
        if (kov[i]==sok) {
            cout << -1 << " ";
        } else {
            cout << kov[i]-i << " ";
        }
    }
    return 0;
}