#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int n, m, k, q, hv[c], cnt;
map<long long, int> p;
set<int> s[c];
int ker(long long x) {
    if (p.find(x)!=p.end()) x=p[x];
    else p[x]=cnt, x=cnt, cnt++;
    return x;
}
int holvan(int a) {
    if (!hv[a]) return a;
    int x=holvan(hv[a]);
    hv[a]=x; return x;
}
void add(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        if (s[a].size()<s[b].size())  swap(a, b);
        hv[b]=a;
        for (auto it=s[b].begin(); it!=s[b].end(); it++) {
            int x=*it;
            s[a].insert(x);
        }
    }
}
void valt() {
    long long a, b, c, x, y;
    cin >> a >> b >> c;
    x=ker(c*n+a), y=ker(c*n+b);
    s[holvan(a)].insert(b), s[holvan(b)].insert(a);
    add(a, y), add(x, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> q, cnt=n+1;
    for (int i=1; i<=n; i++) s[i].insert(i), p[i]=i;
    for (int i=1; i<=m; i++) valt();
    for (int i=1; i<=q; i++) {
        char c;
        cin >> c;
        if (c=='?') {
            int a, b;
            cin >> a >> b;
            a=holvan(a);
            if (s[a].find(b)!=s[a].end()) cout << "Yes\n";
            else cout << "No\n";
        } else valt();
    }
    return 0;
}