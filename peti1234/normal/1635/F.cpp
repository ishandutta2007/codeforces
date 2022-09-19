#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long n, q, pos[c], ert[c], l[c], fen[c], ans[c], sok=5e18;
vector<pair<long long, long long> > sz;
vector<int> s;

int lsb(int a) {
    return (a & -a);
}
void add(int a, long long b) {
    //cout << "add " << a << " " << b << "\n";
    while (a) {
        fen[a]=min(fen[a], b);
        a-=lsb(a);
    }
}
long long ask(int a) {
    //cout << "ask " << a << "\n";
    long long ans=sok;
    while (a<=n) {
        ans=min(ans, fen[a]);
        a+=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> pos[i] >> ert[i];
    }
    for (int i=1; i<=n; i++) {
        while (s.size()>0 && ert[i]<ert[s.back()]) {
            s.pop_back();
        }
        if (s.size()>0) {
            sz.push_back({i, s.back()});
        }
        s.push_back(i);
    }
    s.clear();
    for (int i=n; i>=1; i--) {
        while (s.size()>0 && ert[i]<ert[s.back()]) {
            s.pop_back();
        }
        if (s.size()>0) {
            sz.push_back({s.back(), i});
        }
        s.push_back(i);
    }
    s.clear();
    for (int i=1; i<=q; i++) {
        int r;
        cin >> l[i] >> r;
        sz.push_back({r, i+n});
    }

    sort(sz.begin(), sz.end());
    for (int i=1; i<=n; i++) {
        fen[i]=sok;
    }
    for (auto x:sz) {
        long long fi=x.first, se=x.second;
        //cout << "fontos " << fi << " " << se << "\n";
        if (se<=n) {
            long long p=(pos[fi]-pos[se])*(ert[fi]+ert[se]);
            //cout << "uj " << se << " " << fi << " " << p << "\n";
            add(se, p);
        } else {
            int id=se-n;
            ans[id]=ask(l[id]);
            //cout << "kerdes " << l[id] << " " << fi << " " << ans[id] << "\n";
        }
    }

    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
/*
3 1
-2 2
0 10
1 1

2 3
*/