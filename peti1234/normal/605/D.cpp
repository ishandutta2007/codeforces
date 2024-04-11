#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, cnt, a1[c], b1[c], a2[c], b2[c], dist[c], fel[c];
bool v[c];
vector<int> f, ans;
map<int, int> m;
queue<int> q;
set<pair<int, int> > s[c];
int lsb(int a) {
    return (a & (-a));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;

    f.push_back(0);
    for (int i=1; i<=n; i++) {
        cin >> a1[i] >> b1[i] >> a2[i] >> b2[i];
        f.push_back(a1[i]), f.push_back(a2[i]);
    }
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());

    for (auto x:f) {
        m[x]=++cnt;
    }

    for (int i=1; i<=n; i++) {
        int x=m[a1[i]];
        while (x<=cnt) {
            s[x].insert({b1[i], i});
            x+=lsb(x);
        }
    }

    q.push(0);
    while (q.size()>0) {
        int id=q.front();
        q.pop();
        int x=m[a2[id]], y=b2[id];

        while (x>0) {
            while (s[x].size()>0 && (*s[x].begin()).first<=y) {
                int kov=(*s[x].begin()).second;
                if (!v[kov]) {
                    v[kov]=1;
                    fel[kov]=id;
                    dist[kov]=dist[id]+1;
                    q.push(kov);
                }
                s[x].erase(s[x].begin());
            }
            x-=lsb(x);
        }
    }
    if (!v[n]) {
        cout << -1 << "\n";
    } else {
        int pos=n;
        while (pos) {
            ans.push_back(pos);
            pos=fel[pos];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}