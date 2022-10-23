#include <bits/stdc++.h>

using namespace std;
const int c=1005;
long long n, a[c], b[c];
bool check(long long ert) {
    //cout << "check " << ert << "\n";
    vector<long long> ans;
    bool baj=0;
    multiset<long long> sx, sy;
    for (int i=1; i<=n; i++) {
        sx.insert(a[i]), sy.insert(b[i]);
    }
    while (sx.size()>0 || sy.size()>0) {
        long long x=0, y=0;
        auto it=sx.end();
        it--;
        x=*it;
        it=sy.end();
        it--;
        y=*it;
        long long valt=(x<y), xx=max(x, y), cel=abs(xx-ert), mx=xx;
        //cout << "fontos " << x << " " << y << " " << cel << "\n";
        if (valt) swap(xx, cel);
        //cout << "vege " << xx << " " << cel << "\n";
        if (sx.find(xx)==sx.end() || sy.find(cel)==sy.end()) {
            baj=1, sx.clear(), sy.clear();
            break;
        }
        //cout << "sikerult\n";
        sx.erase(sx.find(xx)), sy.erase(sy.find(cel));
        //cout << "fontos " << xx << "\n";
        long long pos=0;
        if (mx>ert) {
            if (x>=y) pos=mx;
            else pos=ert-mx;
        } else {
            if (x>=y) pos=mx;
            else pos=ert-mx;
        }
        ans.push_back(pos);
    }

    if (!baj) {
        long long mini=0;
        for (auto x:ans) {
            mini=min(mini, x);
        }
        mini*=-1;
        cout << "YES\n";
        for (auto x:ans) {
            cout << x+mini << " ";
        }
        cout << "\n";
        cout << mini << " " << ert+mini << "\n";
        return true;
    }
    //exit(0);
    return false;
}
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    for (int i=1; i<=n; i++) {
        if (check(a[1]+b[i]) || check(abs(a[1]-b[i]))) {
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
2
10 33
26 69
*/