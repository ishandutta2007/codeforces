#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, t[c], kom[c], n, q;
set<long long> s;
void solve(int a, int b) {
    s.insert(kom[b]-kom[a-1]);
    if (t[a]==t[b]) return;
    int ert=(t[a]+t[b])/2, lo=a, hi=b, mid;
    while(hi-lo>1) {
        mid=(hi+lo)/2;
        if (t[mid]<=ert) lo=mid;
        else hi=mid;
    }
    solve(a, lo), solve(lo+1, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> q, s.clear();
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            kom[i]=kom[i-1]+t[i];
        }
        solve(1, n);
        for (int i=1; i<=q; i++) {
            long long x; cin >> x;
            if (s.find(x)==s.end()) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}