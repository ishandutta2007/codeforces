#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, d, t[c];
bool solve(int ert) {
    int el=0, ut=0, gap=0;
    for (int i=1; i<=n; i++) {
        if (i<n && t[i+1]-t[i-1]<ert) {
            return false;
        }
        if (t[i]-t[i-1]<ert) {
            if (!el) el=i;
            ut=i;
        }
        if (t[i]-t[i-1]>=2*ert) gap=1;
    }
    //cout << "proba " << ert << " " << el << " " << ut << "\n";
    if (d-t[n]>=ert) gap=1;
    if (!el) return true;
    if (ut>el+1) return false;
    if (el==ut && el>1 && t[el]-t[el-2]>=2*ert) return true;
    if (el==n) {
        return (gap || d-t[n-1]>=ert);
    }
    return (gap || t[el+1]-t[el-1]>=2*ert);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> d;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        int lo=0, hi=d+2, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (solve(mid)) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        //cout << "valasz.............................. ";
        cout << lo-1 << "\n";
    }
    return 0;
}
/*
1
3 12
3 5 9

*/