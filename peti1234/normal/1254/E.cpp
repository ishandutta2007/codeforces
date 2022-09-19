#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, db[c], szint[c], fel[c], kov[c];
long long ans=1, mod=1e9+7;
vector<int> sz[c];
vector<pair<int, int> > sz2[c];
set<pair<int, int> > s;
bool v[c], v2[c];
void ns() {
    cout << 0 << "\n";
    exit(0);
}
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
        }
    }
}
void add(int a, int b, int c) {
    if (a && s.find({a, b})!=s.end()) ns();
    if (a) s.insert({a, b});
    db[b]--;
    sz2[b].push_back({a, c});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
        db[a]++, db[b]++;
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x) {
            vector<int> kezd, veg;
            int a=i, b=x;
            if (a==b) ns();
            kezd.push_back(0), kezd.push_back(a);
            veg.push_back(0), veg.push_back(b);
            while (a!=b) {
                if (szint[a]>=szint[b]) {
                    a=fel[a];
                    kezd.push_back(a);
                } else {
                    b=fel[b];
                    veg.push_back(b);
                }
            }
            veg.pop_back();
            reverse(veg.begin(), veg.end());
            for (auto x:veg) {
                kezd.push_back(x);
            }
            int si=kezd.size();
            for (int i=0; i<si-2; i++) {
                add(kezd[i], kezd[i+1], kezd[i+2]);
            }
        }
    }
    for (int i=0; i<=n; i++) {
        kov[i]=-1;
    }
    for (int i=1; i<=n; i++) {
        sort(sz2[i].begin(), sz2[i].end());
        for (auto x:sz2[i]) {
            kov[x.first]=x.second;
        }
        for (auto xx:sz2[i]) {
            int x=xx.first;
            if (!v2[x]) {
                int pos=x;
                v2[pos]=1;
                while (kov[pos]!=-1 && !v2[kov[pos]]) {
                    pos=kov[pos];
                    v2[pos]=1;
                }
                if (kov[pos]==x && (x>0 || x==0 && db[i]!=-1)) {
                    ns();
                }
            }
        }
        for (auto x:sz2[i]) {
            kov[x.first]=-1, kov[x.second]=-1, v2[x.first]=0, v2[x.second]=0;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=db[i]; j++) {
            ans=(ans*j)%mod;
        }
    }
    cout << ans << "\n";
    return 0;
}