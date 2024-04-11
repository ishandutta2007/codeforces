#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int ki[c], kor[c], n, m, sum;
vector<pair<int, pair<int, int> > > sz;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        sz.push_back({x, {a, b}});
    }
    sort(sz.rbegin(), sz.rend());
    for (auto p:sz) {
        int x=p.first, a=p.second.first, b=p.second.second;
        a=holvan(a), b=holvan(b);
        if (a==b && kor[a]==0) sum+=x, kor[a]++;
        if (a!=b && kor[a]+kor[b]<=1) sum+=x, kor[a]+=kor[b], ki[b]=a;
    }
    cout << sum << "\n";
    return 0;
}