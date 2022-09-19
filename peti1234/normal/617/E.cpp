#include <bits/stdc++.h>

using namespace std;
const int c=100002, s=(1<<20), gy=350;
int n, k, q, t[c], kom[c], db[s], l[c], r[c];
int bal=1, jobb;
long long ans[c], sum;
vector<pair<int, int> > sz;
void add(int a, int b) {
    int x=kom[a];
    if (b==-1) {
        db[x]--;
    }
    sum+=db[x^k]*b;
    if (b==1) {
        db[x]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kom[i]=kom[i-1]^t[i];
    }
    for (int i=1; i<=q; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
        sz.push_back({l[i]/gy*c+r[i], i});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<q; i++) {
        int id=sz[i].second;
        while (bal>l[id]) {
            bal--;
            add(bal, 1);
        }
        while (jobb<r[id]) {
            jobb++;
            add(jobb, 1);
        }
        while (bal<l[id]) {
            add(bal, -1);
            bal++;
        }
        while (jobb>r[id]) {
            add(jobb, -1);
            jobb--;
        }
        ans[id]=sum;
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}