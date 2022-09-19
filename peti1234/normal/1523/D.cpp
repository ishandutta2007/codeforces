#include <bits/stdc++.h>

using namespace std;
const int c=200005, k=(1<<15);
int n, m, p, db[k], ans;
string s[c], opt;
vector<int> sz;
int vel() {
    long long a=rand(), b=rand();
    return a*b%n+1;
}
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    for (int i=1; i<=50; i++) {
        int pos=vel();
        for (int i=0; i<m; i++) {
            if (s[pos][i]=='1') {
                sz.push_back(i);
            }
        }
        int si=sz.size();
        for (int i=1; i<=n; i++) {
            int ert=0;
            for (int j=0; j<si; j++) {
                if (s[i][sz[j]]=='1') {
                    ert+=(1<<j);
                }
            }
            db[ert]++;
        }
        for (int j=0; j<si; j++) {
            for (int i=0; i<(1<<si); i++) {
                if (i & (1<<j)) {
                    db[i-(1<<j)]+=db[i];
                }
            }
        }
        for (int i=0; i<(1<<si); i++) {
            if (2*db[i]>=n && __builtin_popcount(i)>=ans) {
                ans=__builtin_popcount(i);
                opt.clear();
                for (int j=0; j<m; j++) {
                    opt+='0';
                }
                for (int j=0; j<si; j++) {
                    if (i & (1<<j)) {
                        opt[sz[j]]='1';
                    }
                }
            }
        }
        sz.clear();
        for (int i=0; i<(1<<si); i++) {
            db[i]=0;
        }
    }
    cout << opt << "\n";
    return 0;
}