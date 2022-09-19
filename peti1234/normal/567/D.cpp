#include <bits/stdc++.h>

using namespace std;
int n, a, b, m, t[200002], db, lo, hi, mid;
vector<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> t[i];
    }
    lo=0, hi=m+1;
    while (hi-lo>1) {
        mid=(hi+lo)/2, db=0;
        s.clear();
        s.push_back(0), s.push_back(n+1);
        for (int i=1; i<=mid; i++) {
            s.push_back(t[i]);
        }
        sort(s.begin(), s.end());
        for (int i=1; i<s.size(); i++) {
            db+=(s[i]-s[i-1])/(b+1);
        }
        if (db<a) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    if (hi==m+1) {
        hi=-1;
    }
    cout << hi << "\n";
    return 0;
}