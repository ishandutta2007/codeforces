#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, m, t[c], pref[c];
void add(int l, int r, long long x) {
    pref[l]+=x, pref[r+1]-=x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> t[i];
    }
    for (int i=1; i<m; i++) {
        int l=t[i], r=t[i+1];
        if (l>r) {
            swap(l, r);
        }
        if (l==r) {
            continue;
        }
        add(1, l-1, r-l);
        add(l, l, r-1);
        add(l+1, r-1, r-l-1);
        add(r, r, l);
        add(r+1, n, r-l);
    }
    for (int i=1; i<=n; i++) {
        pref[i]+=pref[i-1];
        cout << pref[i] << " ";
    }
    cout << "\n";
    return 0;
}