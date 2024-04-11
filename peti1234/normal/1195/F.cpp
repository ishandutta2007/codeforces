#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long sok=4e9+1;
int n, q, fen[c], ans[c], pos;
vector<int> uj[c];
vector<pair<pair<int, int>, int> > sz;
unordered_map<long long, int> m;
vector<pair<int, int> > pp;
void pb(int x, int y, int id) {
    int s=abs(__gcd(x, y));
    x/=s, y/=s;
    long long ert=sok*x+y;
    //cout << "fontos " << m[{x, y}] << " " << id << "\n";
    uj[m[ert]].push_back(id);
    m[ert]=id;
}
int lsb(int a) {
    return (a & -a);
}
void add(int a) {
    while (a<c) {
        fen[a]++;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int m;
        cin >> m;
        for (int j=0; j<m; j++) {
            int a, b;
            cin >> a >> b;
            if (j>0) {
                int d1=a-pp.back().first, d2=b-pp.back().second;
                pb(d1, d2, i);
            }
            pp.push_back({a, b});
            if (j+1==m) {
                int d1=pp[0].first-a, d2=pp[0].second-b;
                pb(d1, d2, i);
            }
        }
        pp.clear();
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        sz.push_back({{l, r}, i});
    }
    sort(sz.begin(), sz.end());
    for (auto p:sz) {
        int l=p.first.first, r=p.first.second, id=p.second;
        while (pos<l) {
            for (auto x:uj[pos]) {
                add(x);
            }
            pos++;
        }
        ans[id]=ask(r)-ask(l-1);
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}