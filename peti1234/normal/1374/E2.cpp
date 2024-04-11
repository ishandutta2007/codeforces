#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
int n, m, k, p, q, r, s, sum, mini, pp, qq, rr, ss, sok=INT_MAX;
vector<pair<int, int> > a, b, c, d;
bool baj;
void kell() {
    while(p<a.size() && p+r<k) sum+=a[p].first, p++;
    while(q<b.size() && q+r<k) sum+=b[q].first, q++;
    if (s>0) s--, sum-=d[s].first;
    if (p+r<k || q+r<k) baj=1;
}
void valaszt() {
    while(p+q+r+s<m) {
        int x=sok, y=sok, z=sok, l;
        if (p<a.size()) x=a[p].first;
        if (q<b.size()) y=b[q].first;
        if (s<d.size()) z=d[s].first;
        l=min({x, y, z});
        if (l==sok) {baj=1; break;}
        if (x==l) sum+=a[p].first, p++;
        else if (y==l) sum+=b[q].first, q++;
        else if (z==l) sum+=d[s].first, s++;
    }
    if (p+q+r+s>m) baj=1;
}
void valt() { if (!baj && sum<mini) mini=sum, pp=p, qq=q, rr=r, ss=s; }
int main()
{
    cin >> n >> m >> k, mini=sok;
    for (int i=1; i<=n; i++) {
        int p, x, y;
        cin >> p >> x >> y;
        if (x && !y) a.push_back({p, i});
        if (!x && y) b.push_back({p, i});
        if (x && y) c.push_back({p, i});
        if (!x && !y) d.push_back({p, i});
    }
    sort(all(a)), sort(all(b)), sort(all(c));
    while(c.size()>k) d.push_back(c.back()), c.pop_back();
    sort(all(d));
    while(r<c.size()) sum+=c[r].first, r++;
    kell(), valaszt();
    if (baj) {cout << "-1\n"; return 0;}
    valt();
    while(r>0) {
        r--, sum-=c[r].first;
        kell(), valaszt(), valt();
    }
    cout << mini << "\n";
    for (int i=0; i<pp; i++) cout << a[i].second << " ";
    for (int i=0; i<qq; i++) cout << b[i].second << " ";
    for (int i=0; i<rr; i++) cout << c[i].second << " ";
    for (int i=0; i<ss; i++) cout << d[i].second << " ";
    return 0;
}