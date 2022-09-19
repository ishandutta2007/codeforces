#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, pl=0, mi=0, nu=0;
    cin >> n;
    set<long long> s;
    vector<long long> sz;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        bool f=0;
        if (x>0) {
            pl++;
            if (pl<=3) f=1;
        }
        if (x<0) {
            mi++;
            if (mi<=3) f=1;
        }
        if (x==0) {
            nu++;
            if (nu<=3) f=1;
        }
        if (f) {
            sz.push_back(x);
            s.insert(x);
        }
    }
    bool jo=1;
    int si=sz.size();
    for (int i=0; i<si; i++) {
        for (int j=i+1; j<si; j++) {
            for (int k=j+1; k<si; k++) {
                long long sum=sz[i]+sz[j]+sz[k];
                if (s.find(sum)==s.end()) {
                    jo=0;
                }
            }
        }
    }
    cout << (jo ? "YES" : "NO") << "\n";
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