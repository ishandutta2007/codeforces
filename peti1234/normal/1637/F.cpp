#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long pos, ert, ans, sum, o=0;
int n, t[c], maxi[c], dom[c];
vector<int> sz[c];
vector<pair<int, int> > s;
bool v[c], v2[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            maxi[a]=max(maxi[a], maxi[x]);
            if (a==pos) {
                s.push_back({maxi[x], x});
            }
        }
    }
    dom[a]=max(0, t[a]-maxi[a]);
    sum+=dom[a];
    maxi[a]=max(maxi[a], t[a]);
}

void dfs2(int a) {
    v2[a]=true;
    ans=min(ans, ert+sum);
    for (auto x:sz[a]) {
        if (!v2[x]) {
            long long valt=dom[x];
            if (a==pos && x==s[0].second) {
                valt-=s[0].first-s[1].first;
            }
            sum-=valt;
            dfs2(x);
            sum+=valt;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]>t[pos]) pos=i;
    }
    ert=t[pos];
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(pos);
    ans=ert+sum;
    //cout << ans << "\n";
    s.push_back({0, 0});
    sort(s.rbegin(), s.rend());

    dfs2(pos);
    cout << ans << "\n";
    return 0;
}