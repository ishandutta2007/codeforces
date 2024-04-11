#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n;
long long ans[c], mod=998244353;
vector<int> sz[c], spec;
bool v[c];

int dfs(int a, int ert) {
    v[a]=true;
    int db=0;
    for (auto x:sz[a]) {
        if (!v[x]) {
            int s=dfs(x, ert);
            if (s==-1) {
                return -1;
            }
            db+=s;
        }
    }
    db%=ert;
    if (db==ert-1) {
        return 0;
    }
    if (db==0) {
        return 1;
    }
    return -1;
}

bool solve(int a) {
    for (int i=1; i<=n; i++) {
        v[i]=0;
    }
    return (dfs(1, a)==1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        for (int i=n; i>=2; i--) {
            if ((n-1)%i==0) {
                bool jo=1;
                for (auto x:spec) {
                    if (x%i==0) {
                        jo=0;
                    }
                }
                //cout  << "proba " << i << "\n";
                if (jo && solve(i)) {
                    spec.push_back(i);
                    ans[i]=1;
                }
            }
        }
        long long po=1;
        for (int i=1; i<n; i++) {
            po*=2;
            po%=mod;
        }
        po=(po+mod-spec.size())%mod;
        ans[1]=po;
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            v[i]=0, ans[i]=0;
        }
        spec.clear();
    }
    return 0;
}
/*
1
5
1 2 1 3
2 4 2 5
*/