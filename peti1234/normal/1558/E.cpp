#include <bits/stdc++.h>
 
using namespace std;
const int c=2005;
int w, n, m;
long long aa[c], bb[c];
vector<int> sz[c];
int cnt, fel[c];
long long pl[c];
bool v[c], kesz[c];
void add(int a, long long &val) {
    kesz[a]=1;
    cnt++;
    val+=bb[a];
}
bool solve2(long long &val) {
    queue<int> q;
    for (int i=1; i<=n; i++) {
        v[i]=0, pl[i]=0;
    }
    for (int i=1; i<=n; i++) {
        if (kesz[i]) {
            q.push(i);
            v[i]=1;
        }
    }
    while (q.size()>0) {
        int a=q.front();
        q.pop();
        for (auto x:sz[a]) {
            if (x==fel[a] || kesz[a] && kesz[x]) {
                continue;
            }
            if (val+pl[a]>aa[x]) {
                if (!v[x]) {
                    v[x]=1;
                    fel[x]=a, pl[x]=pl[a]+bb[x];
                    q.push(x);
                } else {
                    int s1=a, s2=x;
                    while (!kesz[s1]) {
                        add(s1, val);
                        s1=fel[s1];
                    }
                    while (!kesz[s2]) {
                        add(s2, val);
                        s2=fel[s2];
                    }
                    return true;
                }
            }
        }
    }
    return false;
}
 
bool solve(long long val) {
    kesz[1]=1, cnt=1;
    while (solve2(val)) {
 
    }
    for (int i=1; i<=n; i++) {
        kesz[i]=0;
    }
    return (cnt==n);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int tc=1; tc<=w; tc++) {
        cin >> n >> m;
        for (int i=2; i<=n; i++) {
            cin >> aa[i];
        }
        for (int i=2; i<=n; i++) {
            cin >> bb[i];
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        int lo=0, hi=1e9+5, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (solve(mid)) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        cout << hi << "\n";
        for (int i=1; i<=n; i++) {
            sz[i].clear();
        }
    }
    return 0;
}