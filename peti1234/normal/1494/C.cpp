#include <bits/stdc++.h>

using namespace std;
int w, n, m, ans, kom[200002];
vector<int> aa, bb, a, b;
int solve() {
    int sa=a.size(), sb=b.size();
    int pos=0, maxi=0, cnt=0;
    for (int i=0; i<sa; i++) {
        while (pos<sb && a[i]>b[pos]) {
            pos++;
        }
        kom[i+1]=kom[i];
        if (pos<sb && a[i]==b[pos]) {
            kom[i+1]++;
            cnt++;
        }
    }
    for (int i=0; i<sb; i++) {
        int lo=-1, hi=sa, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (a[mid]<=b[i]) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        int valtdb=lo+1;
        lo=-1, hi=i+1;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (b[i]-b[mid]>=valtdb) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        maxi=max(maxi, i-hi+1-kom[valtdb]);
    }
    return cnt+maxi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        ans=0;
        aa.clear(), bb.clear(), a.clear(), b.clear();
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x<0) {
                a.push_back(-x);
            } else {
                aa.push_back(x);
            }
        }
        for (int i=1; i<=m; i++) {
            int x; cin >> x;
            if (x<0) {
                b.push_back(-x);
            } else {
                bb.push_back(x);
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        ans+=solve();
        a=aa, b=bb;
        ans+=solve();
        cout << ans << "\n";
    }
    return 0;
}
/*
1
2 2
-1000000000 1000000000
-1 1
*/