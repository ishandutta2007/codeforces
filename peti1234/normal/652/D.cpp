#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, fen[c], ans[c], cnt, db;
set<int> s;
map<int, int> m;
vector<pair<pair<int, int>, int> > sz;
int lsb(int a) {
    return (a & -a);
}
void add(int a) {
    while (a<=n) {
        fen[a]++;
        a+=lsb(a);
    }
}
int ask(int a) {
    int res=0;
    while (a) {
        res+=fen[a];
        a-=lsb(a);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        s.insert(a);
        sz.push_back({{b, a}, i});
    }
    for (auto x:s) {
        m[x]=++cnt;
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        int a=m[x.first.second], id=x.second;
        ans[id]=db-ask(a);
        add(a), db++;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}