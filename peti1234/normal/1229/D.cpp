#include <bits/stdc++.h>

using namespace std;
const int c2=200005, c=125, k=120;
long long ans;
map<vector<int>, int> perm;
map<int, vector<int> > rev;
int t[c2], kov[c2][c], mul[c][c], n, m;
bool v[c], v2[c];
vector<int> csop;
void dfs (int a) {
    v2[a]=true;
    v[a]=true;
    for (auto x:csop) {
        int s=mul[a][x];
        if (!v2[s]) dfs(s);
    }
}
int add(int a) {
    for (int i=1; i<=k; i++) v2[i]=0;
    csop.push_back(a);
    dfs(1);
    int cnt=0;
    for (int i=1; i<=k; i++) cnt+=v[i];
    return cnt;
}
int main()
{
    vector<int> s={1, 2, 3, 4, 5};
    for (int i=1; i<=k; i++) {
        perm[s]=i;
        rev[i]=s;
        next_permutation(s.begin(), s.end());
    }
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k; j++) {
            vector<int> a=rev[i], b=rev[j], res;
            for (int p=0; p<5; p++) {
                res.push_back(a[b[p]-1]);
            }
            mul[i][j]=perm[res];
        }
    }

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        vector<int> p;
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            p.push_back(x);
        }
        for (int j=m+1; j<=5; j++) {
            p.push_back(j);
        }
        t[i]=perm[p];
    }
    for (int i=1; i<=k; i++) {
        kov[n+1][i]=n+1;
    }
    for (int i=n; i>=1; i--) {
        vector<pair<int, int> > sz;
        for (int j=1; j<=k; j++) {
            kov[i][j]=(t[i]==j ? i : kov[i+1][j]);
            if (kov[i][j]!=n+1 && t[i]!=j) sz.push_back({kov[i][j], j});
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<=k; i++) v[i]=0;
        csop.clear();
        v[1]=1;

        int ut=i, ert=add(t[i]);
        for (auto x:sz) {
            if (!v[x.second]) {
                ans+=(x.first-ut)*ert;
                ut=x.first;
                ert=add(x.second);
            }
        }
        ans+=(n+1-ut)*ert;
    }

    cout << ans << "\n";
    return 0;
}