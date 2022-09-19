#include <bits/stdc++.h>

using namespace std;
const int c=2505;
int n, cnt, si[c], ki[c], el;

vector<pair<int, pair<int, int> > > sz;

int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        cnt+=2*si[a]*si[b];
        si[a]+=si[b];
        ki[b]=a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cnt=n;
    for (int i=1; i<=n; i++) {
        si[i]=1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            sz.push_back({x, {i, j}});
        }
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<n*n; i++) {
        if (sz[i].first!=el && cnt!=i) {
            cout << "NOT MAGIC\n";
            return 0;
        }
        unio(sz[i].second.first, sz[i].second.second);
        el=sz[i].first;
    }
    cout << "MAGIC\n";
    return 0;
}