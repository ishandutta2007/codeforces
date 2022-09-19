#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, m, t[c], ki[c], si[c];
long long k, sum, rdb;
vector<pair<pair<int, int>, pair<int, int> > > el;
vector<int> uj;
bool rossz[c];
int holvan(int a) {
    if (!ki[a]) return a;
    return holvan(ki[a]);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        if (si[b]<si[a]) {
            uj.push_back(b);
            ki[b]=a;
            si[a]+=si[b];
        } else {
            uj.push_back(a);
            ki[a]=b;
            si[b]+=si[a];
        }
    }
}
void add(int a, int b, int x, int y) {
    el.push_back({{a, b}, {x, y}});
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=2*n; i++) si[i]=1;
    for (int i=1; i<=m; i++) {
        int a, b, x, y;
        cin >> x >> y, a=t[x], b=t[y];
        if (a>b) swap(a, b);
        if (a==b) {
            unio(x, y+n);
            unio(y, x+n);
        } else {
            add(a, b, x, y);
        }
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)==holvan(i+n)) {
            if (!rossz[t[i]]) {
                rdb++;
                rossz[t[i]]=1;
            }
        }
    }
    sum=(k-rdb)*(k-rdb-1)/2;
    add(0, 0, 0, 0);
    add(k+1, k+1, 0, 0);
    sort(el.begin(), el.end());
    uj.clear();
    for (int i=1; i<el.size(); i++) {
        pair<int, int> p=el[i].first, q=el[i-1].first, cs=el[i].second;
        if (p!=q) {
            int baj=0;
            for (int i=0; i<uj.size(); i++) {
                int x=uj[i], y=uj[i]+n;
                if (x>n) y-=2*n;
                if (holvan(x)==holvan(y)) baj=1;
                si[holvan(x)]-=si[x];
                ki[x]=0;
            }
            if  (!rossz[q.first] && !rossz[q.second] && baj) sum--;
            uj.clear();
        }
        int fi=cs.first, se=cs.second;
        unio(fi, se+n), unio(se, fi+n);
    }
    cout << sum << "\n";
    return 0;
}