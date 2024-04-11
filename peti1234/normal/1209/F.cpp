#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long ans[c], mod=1000000007;
int n, cnt, m;
vector<pair<int, int> > sz[c];
queue<vector<pair<int, long long> > > q;
bool v[c];
void add(int a, int b, int c) {
    //cout << a << " " << b << " " << c << "\n";
    sz[a].push_back({b, c});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cnt=n;
    for (int i=1; i<=m; i++) {
        int a, b, si;
        cin >> a >> b;
        vector<int> cs, ert;
        cs.push_back(a), ert.push_back(i%10);
        int  ii=i/10;
        while (ii) {
            cs.push_back(++cnt), ert.push_back(ii%10);
            ii/=10;
        }
        cs.push_back(b);
        si=cs.size();
        for (int i=0; i<si-1; i++) {
            add(cs[i], cs[i+1], ert[si-2-i]);
        }
        for (int i=si-1; i>=1; i--) {
            add(cs[i], cs[i-1], ert[i-1]);
        }
    }
    q.push({{1, 0}});
    while (q.size()>0) {
        auto t=q.front();
        q.pop();
        vector<pair<int, long long> > kov[10];
        for (auto cs:t) {
            int fi=cs.first;
            long long ert=cs.second%mod;
            if (!v[fi]) {
                v[fi]=1;
                ans[fi]=ert;
                for (auto x:sz[fi]) {
                    int uj=x.first, suly=x.second;
                    if (!v[uj]) {
                        kov[suly].push_back({uj, (10*ert+suly)%mod});

                    }
                }
            }
        }
        for (int i=0; i<10; i++) {
            if (kov[i].size()>0) {
                q.push(kov[i]);
            }
        }
    }
    for (int i=2; i<=n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}