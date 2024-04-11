#include <bits/stdc++.h>

using namespace std;
const int c=100005, sok=2e9;
int n, m, cnt, ans=sok+1, t[c][5], ert[c];
long long r[5]={123456789, 987654321, 87654319, 23456891, 54637219};
vector<pair<int, int> > sz;
unordered_map<long long, int> p;
void add(int a, int b) {
    cnt+=b;
    for (int i=1; i<(1<<m); i++) {
        long long sum=0, cnt=0;
        for (int j=0; j<m; j++) {
            if (i & (1<<j)) {
                sum+=r[cnt++]*t[a][j];
            }
        }
        p[sum]+=b;
    }
}
bool jo(int a) {
    int ert=0;
    for (int i=1; i<(1<<m); i++) {
        long long sum=0, cnt=0;
        for (int j=0; j<m; j++) {
            if (i & (1<<j)) {
                sum+=r[cnt++]*t[a][j];
            }
        }
        if (cnt%2) ert+=p[sum];
        else ert-=p[sum];
    }
    return (ert<cnt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            cin >> t[i][j];
        }
        cin >> ert[i];
        sz.push_back({ert[i], i});
        sort(t[i], t[i]+m);
    }
    sort(sz.begin(), sz.end());
    int pos=0;
    while (pos<n && !jo(sz[pos].second)) {
        add(sz[pos].second, 1);
        pos++;
    }
    if (pos<n) {
        pos--;
        ans=sz[pos].first+sz[pos+1].first;
        for (int i=pos+1; i<n; i++) {
            if (sz[i].first+sz[0].first>=ans) {
                break;
            }
            while(jo(sz[i].second)) {
                add(sz[pos].second, -1);
                pos--;
            }
            ans=min(ans, sz[i].first+sz[pos+1].first);
        }
    }
    cout << (ans<=sok ? ans : -1) << "\n";
    return 0;
}