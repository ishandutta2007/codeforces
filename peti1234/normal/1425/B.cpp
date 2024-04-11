#include <bits/stdc++.h>

using namespace std;
const int c=4002, k=c/2, mod=1e9+7;
vector<int> sz[c];
int n, m, db[c];
long long regi[c][2], uj[c][2], sum;
bool v[c];
long long ks() {
    for (int i=0; i<c; i++) {
        regi[i][0]=0, regi[i][1]=0;
    }
    regi[k][0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=db[i]; j++) {
            for (int l=0; l<c; l++) {
                uj[l][0]=0;
                uj[l][1]=regi[l][0]+regi[l][1];
                if (l>=i) {
                    uj[l][0]+=regi[l-i][0];
                    uj[l][1]+=regi[l-i][1];
                }
                if (l+i<c) {
                    uj[l][0]+=regi[l+i][0];
                    uj[l][1]+=regi[l+i][1];
                }
                uj[l][0]%=mod;
                uj[l][1]%=mod;
            }
            for (int l=0; l<c; l++) {
                regi[l][0]=uj[l][0];
                regi[l][1]=uj[l][1];
            }
        }
    }
}
void dfs(int a, int b) {
    v[a]=true;
    bool ve=0;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x, b+1);
        }
        if (x==1) {
            if (!ve && b==2) ve=1;
            else db[b]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }

    dfs(1, 1);
    ks();
    sum+=regi[k][0];
    for (int i=1; i<=n; i++) {
        if (db[i]) {
            db[i]--;
            ks();
            db[i]++;
            long long cnt=0;
            cnt+=regi[k-i+1][0]+regi[k+i-1][0];
            for (int j=k-i+2; j<=k+i-2; j++) {
                cnt+=regi[j][0]+regi[j][1];
            }
            cnt%=mod;
            sum+=2*cnt*db[i];
            sum%=mod;
        }
    }
    cout << sum << "\n";
    return 0;
}