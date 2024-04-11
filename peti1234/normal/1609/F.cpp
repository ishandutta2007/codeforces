#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int c=1000005;
long long n, ans, cnt, t[c], dom[c][2], fen[c][2][2];
vector<int> s[2];
int addcnt;
long long ask(int pos, int a, int b) {
    int ans=0;
    while (pos) {
        ans+=fen[pos][a][b];
        pos-=(pos & -pos);
    }
    return ans;
}
int range_ask(pair<int, int> p, int id) {
    int l=p.first, r=p.second;
    long long kis=(l-1)*ask(l-1, id, 0)-ask(l-1, id, 1), nagy=r*ask(r, id, 0)-ask(r, id, 1);
    return nagy-kis;
}
void add(int pos, int ert, int a, int b) {
    while (pos<=n) {
        fen[pos][a][b]+=ert;
        pos+=(pos & -pos);
    }
}
void range_add(pair<int, int> p, int id, int ert) {
    addcnt++;
    int l=p.first, r=p.second;
    cnt+=ert*range_ask(p, 1-id);
    add(l, ert, id, 0), add(r+1, -ert, id, 0);
    add(l, (l-1)*ert, id, 1), add(r+1, -ert*r, id, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    s[0].push_back(n+1), s[1].push_back(n+1);
    for (int i=n; i>=1; i--) {
        for (int j=0; j<2; j++) {
            int sgn=(j==0 ? -1 : 1);
            while (s[j].back()<n+1 && t[i]*sgn>t[s[j].back()]*sgn) s[j].pop_back();
            dom[i][j]=s[j].back()-1;
            s[j].push_back(i);
        }
    }
    for (int pc=0; pc<60; pc++) {
        vector<pair<int, int> > s[2];
        s[0].push_back({n+1, n+1}), s[1].push_back({n+1, n+1});
        for (int i=n; i>=1; i--) {
            for (int j=0; j<2; j++) {
                while (dom[i][j]>=s[j].back().second) {
                    range_add(s[j].back(), j, -1);
                    s[j].pop_back();
                }
                if (__builtin_popcountll(t[i])==pc) {
                    s[j].push_back({i, dom[i][j]});
                    range_add(s[j].back(), j, 1);
                }
            }
            ans+=cnt;
        }
        for (int j=0; j<2; j++) {
            while (s[j].size()>1) {
                range_add(s[j].back(), j, -1);
                s[j].pop_back();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}