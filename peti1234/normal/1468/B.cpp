#include <bits/stdc++.h>

using namespace std;
const int c=200002, sok=2e9;
long long t[c], kom[c], h[c], ki[c], n, m, maxi;
priority_queue<pair<long long, int> > q;
vector<pair<long long, int> > ans;
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    ki[b]=a;
    h[a]+=h[b];
}
void pb(int l, int r) {
    long long sum=kom[r]-kom[l-1], d=(r-l+1), atl=(sum-1)/d;
    q.push({atl, l});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kom[i]=kom[i-1]+t[i], h[i]=1;
        if (i<n) {
            pb(i, i);
        }
    }
    ans.push_back({sok, 0});
    n--;
    while (q.size()>0) {
        long long ert=q.top().first, id=q.top().second;
        q.pop();
        if (!ki[id]) {
            maxi=max(maxi, h[id]+h[id+h[id]]-1);
            ans.push_back({ert, maxi});
            int kov=id+h[id];
            if (kov!=n+1) {
                unio(id, kov);
                pb(id, id+h[id]-1);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    int si=ans.size();
    for (int i=si-2; i>=0; i--) {
        ans[i].first=min(ans[i].first, ans[i+1].first);
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        int lo=-1, hi=ans.size(), mid;
        while (hi-lo>1) {
            mid=(lo+hi)/2;
            if (ans[mid].first>=x) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        cout << ans[hi].second << " ";
    }
    cout << "\n";
    return 0;
}