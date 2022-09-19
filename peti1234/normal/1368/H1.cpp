#include <bits/stdc++.h>

using namespace std;
int n, m, q, ans;
string s[4];
deque<pair<int, char> > bal, jobb, ss;
void valt(deque<pair<int, char> > &sor) {
    ss.clear();
    bool t=1;
    while (sor.size()>0) {
        int db=sor.front().first;
        char c=sor.front().second;
        if (ss.size()>0 && c!=ss.back().second && t) {
            t=0;
            ans++;
            ss.back().first--;
            sor.front().first--;
            db--;
            if (!ss.back().first) {
                ss.pop_back();
            }
        }
        if (db>0) {
            t=1;
            if (ss.size()>0 && c==ss.back().second) {
                ss.back().first+=db;
            } else {
                ss.push_back(sor.front());
            }
        }
        sor.pop_front();
    }
    ss.front().first=min(ss.front().first, n);
    sor=ss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=0; i<4; i++) {
        cin >> s[i];
    }
    if (n>m) {
        swap(n, m);
        swap(s[0], s[2]), swap(s[1], s[3]);
    }
    for (int i=0; i<n; i++) {
        bal.push_back({1, s[0][i]});
        jobb.push_back({1, s[1][i]});
    }
    for (int i=0; i<m/2; i++) {
        bal.push_front({1, s[2][i]});
        bal.push_back({1, s[3][i]});
        valt(bal);
    }
    for (int i=m-1; i>=m/2; i--) {
        jobb.push_front({1, s[2][i]});
        jobb.push_back({1, s[3][i]});
        valt(jobb);
    }
    int sb=bal.size(), sj=jobb.size();
    if (sb && sj) {
        if (sb==1 && sj==1) {
            if (bal.front().second!=jobb.front().second) {
                ans+=min(bal.front().first, jobb.front().first);
            }
        } else {
            if (sj==1) {
                swap(sj, sb);
                swap(bal, jobb);
            }
            if (sb==1) {
                if (bal.front().second!=jobb.front().second) {
                    ans+=min(bal.front().first, jobb.front().first);
                } else {
                    ans+=min(bal.front().first, jobb.back().first);
                }
            } else {
                if (bal.front().second==jobb.front().second) {
                    ans+=max(min(bal.front().first, jobb.back().first), min(bal.back().first, jobb.front().first));
                } else {
                    ans+=min(bal.front().first, jobb.front().first)+min(bal.back().first, jobb.back().first);
                }

            }
        }
    }
    cout << ans << "\n";
    return 0;
}