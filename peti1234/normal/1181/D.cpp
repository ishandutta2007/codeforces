#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long m, n, q, db[c], t[c], ans[c], pos, cnt;
vector<pair<long long, int> > sz, ert;
int lsb(int a) {
    return (a & (-a));
}
void add(int a) {
    while (a<=n) {
        t[a]++;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=t[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> q;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    for (int i=1; i<=n; i++) {
        ert.push_back({db[i], i});
    }
    pos=1, cnt=m;
    sort(ert.begin(), ert.end());
    add(ert[0].second);
    for (int i=1; i<=q; i++) {
        long long x;
        cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<q; i++) {
        long long val=sz[i].first, id=sz[i].second;
        while (pos<n && cnt+(ert[pos].first-ert[pos-1].first)*pos<val) {
            cnt+=(ert[pos].first-ert[pos-1].first)*pos;
            add(ert[pos].second);
            pos++;
        }
        long long mar=(val-cnt)%pos;
        if (mar==0) {
            mar=pos;
        }
        int lo=0, hi=n, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (ask(mid)>=mar) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        ans[id]=hi;
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}