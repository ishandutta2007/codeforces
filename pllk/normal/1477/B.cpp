#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s, f;
        cin >> s >> f;
        set<vector<int>> z;
        for (int i = 0; i < n; i++) {
            z.insert({i,i,f[i]-'0'});
        }
        int l[q], r[q];
        for (int i = 0; i < q; i++) {
            cin >> l[i] >> r[i];
            l[i]--; r[i]--;
        }
        int h = 1;
        for (int i = q-1; i >= 0; i--) {
            auto it = z.upper_bound({l[i],n,1});
            it--;
            int w = r[i]-l[i]+1;
            int s = 0;
            while (it != z.end()) {
                auto v = *it;
                it++;
                if (v[0] > r[i]) break;
                int a = max(v[0],l[i]);
                int b = min(v[1],r[i]);
                s += (b-a+1)*v[2];
                z.erase(v);
                if (v[0] < l[i]) {
                    z.insert({v[0],l[i]-1,v[2]});
                }
                if (v[1] > r[i]) {
                    z.insert({r[i]+1,v[1],v[2]});
                }
            }
            if (2*s == w) {h = 0; break;}
            int u = 2*s > w;
            z.insert({l[i],r[i],u});
        }
        string d(n,'x');
        for (auto v : z) {
            for (int i = v[0]; i <= v[1]; i++) {
                d[i] = v[2]+'0';
            }
        }
        if (d != s) h = 0;
        if (h) cout << "YES\n";
        else cout << "NO\n";
    }
}