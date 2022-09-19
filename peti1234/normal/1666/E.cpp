#include <bits/stdc++.h>

using namespace std;
long long n, len, lo, hi, mid, mini, maxi, t[100005];
vector<pair<long long, long long> > p, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> len >> n;
    t[n+1]=len;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    lo=0, hi=len+1;
    while (hi-lo>1) {
        // a legkisebb minel hosszabb legyen
        mid=(hi+lo)/2;
        bool baj=0;
        long long pos=0;
        for (int i=1; i<=n; i++) {
            if (pos>t[i]) baj=1;
            pos=max(pos+mid, t[i]);
        }
        if (baj) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    mini=lo;

    lo=0, hi=len;
    while (hi-lo>1) {
        // a legnagyobb minel rovidebb legyen
        mid=(hi+lo)/2;
        bool baj=0;
        long long pos=0;
        for (int i=1; i<=n; i++) {
            if (t[i]-pos>mid) baj=1;
            pos=min(pos+mid, t[i+1]);
        }
        if (pos<len) {
            baj=1;
        }
        if (baj) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    maxi=hi;
    //cout << mini << " " << maxi << "\n";
    //cout << maxi-mini << "\n";
    long long x=0, y=0, ert=len;
    p.push_back({x, y});
    for (int i=1; i<=n; i++) {
        x=max(t[i], x+mini);
        y=min(t[i+1], y+maxi);
        p.push_back({x, y});
    }
    for (int i=n-1; i>=0; i--) {
        long long kov=min(ert-mini, p[i].second);
        ans.push_back({kov, ert});
        ert=kov;
    }
    reverse(ans.begin(), ans.end());
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}