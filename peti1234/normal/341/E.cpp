#include <bits/stdc++.h>

using namespace std;
int n, t[1002], a, b;
vector<pair<int, int> > ans;
void l(int a, int b) {
    /*if (t[a]<t[b]) {
        cout << "Nagyonnagybaj\n";
    }*/
    ans.push_back({b, a});
    t[a]-=t[b], t[b]+=t[b];
}
int cnt=0;
void solve(int c) {
    while (t[a]>0 && t[b]>0 && t[c]>0) {
        //if (++cnt==10) break;
        //cout << "kezd " << t[a] << "\n";
        while (t[a]>t[b]) l(a, b);
        while (t[a]>t[c]) l(a, c);
        if (!t[a]) break;
        if (t[b]>t[c]) swap(b, c);
        while (2*t[b]<t[c]) l(c, b);
        if (t[b]>t[c]) swap(b, c);
        int aa=t[a];
        while (2*aa<=t[b]) aa*=2;
        int bb=aa+t[b]%t[a];
        if (2*(bb-aa)>t[a]) bb-=t[a];
        if (t[a]+t[b]>aa+bb) bb+=t[a];
        //cout << "alap " << t[a] << " " << t[b] << " " << t[c] << "\n";
        //cout << "terv " << aa << " " << bb << " " << abs(aa-bb) << "\n";
        while (t[a]<aa) {
            if ((t[b]-bb)%(2*t[a])) l(b, a);
            else l(c, a);
        }
        //cout << "vege " << t[a] << " " << t[b] << "\n";
        if (t[a]>t[b]) swap(a, b);
        l(b, a);
        swap(a, b);
        //cout << "veg " << t[a] << "\n";
        /*if (ans.size()>20000) {
            exit(0);
        }*/
    }
    if (!t[a]) swap(a, c);
    if (!t[b]) swap(b, c);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> sz;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]) sz.push_back(i);
    }
    int si=sz.size();
    if (si<2) {
        cout << -1 << "\n";
        return 0;
    }
    a=sz[0], b=sz[1];
    for (int i=2; i<si; i++) {
        solve(sz[i]);
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    /*for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";*/
    return 0;
}
/*
3
38 84 67
*/
/*
3
304 672 536
*/