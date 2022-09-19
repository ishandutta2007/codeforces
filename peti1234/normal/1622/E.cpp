#include <bits/stdc++.h>

using namespace std;
const int c=10005;
int w, n, m, v[c];
vector<int> sz[1024], p[11];
vector<int> opt, pr;
string s[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int db=1; db<=10; db++) {
        int s=(1<<db);
        for (int i=0; i<s; i++) p[db].push_back(i);
        for (int i=0; i<s; i++) {
            for (int j=i+1; j<s; j++) {
                if (__builtin_popcount(p[db][i])<__builtin_popcount(p[db][j])) {
                    swap(p[db][i], p[db][j]);
                }
            }
        }
    }
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        for (int i=0; i<n; i++) {
            cin >> s[i];
        }
        for (int i=0; i<m; i++) {
            int sum=0;
            for (int j=0; j<n; j++) {
                if (s[j][i]=='1') sum+=(1<<j);
            }
            sz[sum].push_back(i);
        }
        int n2=(1<<n), ans=-1;
        opt.resize(m), pr.resize(m);
        for (int mask=0; mask<n2; mask++) {
            int ert=-m*(m+1)/2*(n-__builtin_popcount(mask));
            for (int i=0; i<n; i++) {
                if (mask & (1<<i)) ert-=v[i];
                else ert+=v[i];
            }
            //cout << "kezd " << mask << " " << ert << "\n";
            int cnt=0;
            for (auto xx:p[n]) {
                int x=xx^mask, pc=n-__builtin_popcount(xx);
                if (mask==0) {
                    //cout << "ertek " << x << " " << xx << " " << pc << "\n";
                }
                for (auto y:sz[x]) {
                    //cout << "vege " << x << " " << y << "\n";
                    ert+=(++cnt)*pc;
                    pr[y]=cnt;
                }
            }
            //cout << "veg " << ert << "\n";
            if (ert>ans) {
                //cout << "valt " << mask << "\n";
                ans=ert;
                opt=pr;
            }
            //break;
        }

        for (auto x:opt) {
            cout << x << " ";
        }
        cout << "\n";

        for (int i=0; i<n2; i++) sz[i].clear();
        opt.clear(), pr.clear();

    }
    return 0;
}
/*
1
3 6
20 3 15
010110
000101
111111
*/