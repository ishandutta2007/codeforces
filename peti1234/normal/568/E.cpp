#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m, t[c], visz[c], ert[c], pos[c], lis;
vector<int> p;
multiset<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    n++;
    t[n]=1e9+1;
    cin >> m;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        p.push_back(x);
        s.insert(x);
    }
    sort(p.begin(), p.end());
    for (int i=1; i<=n; i++) {
        if (t[i]==-1) {
            int k=lis;
            for (int i=m-1; i>=0; i--) {
                while (p[i]<=ert[k]) k--;
                ert[k+1]=p[i];
                pos[k+1]=pos[k];
                lis=max(lis, k+1);
            }
        } else {
            int lo=0, hi=lis+1, mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (ert[mid]<t[i]) lo=mid;
                else hi=mid;
            }
            ert[hi]=t[i];
            visz[i]=pos[hi-1], pos[hi]=i;
            lis=max(lis, hi);
        }
    }
    int ut=t[n], kov=visz[n];
    for (int i=n-1; i>0; i--) {
        if (i==kov) {
            ut=t[i];
            kov=visz[i];
        }
        auto x=s.upper_bound(t[kov]);
        if (t[i]==-1 && x!=s.end() && *x<ut) {
            auto it=s.lower_bound(ut);
            it--;
            t[i]=*it;
            ut=*it;
            s.erase(it);
        }
    }
    for (int i=1; i<n; i++) {
        if (t[i]==-1) {
            t[i]=*s.begin();
            s.erase(s.begin());
        }
        cout << t[i] << " ";
    }
    return 0;
}