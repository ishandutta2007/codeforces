#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, m, db[c], grundy[c];
vector<int> sz[c], s[c], k[c];
queue<int> q;
const int cc=515;
long long mod=998244353;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long t[cc][cc];
long long pos[cc], sol[cc];
void gauss_elimination(int n) {
    for (int i=1; i<=n; i++) {
        int ert=0;
        for (int j=1; j<=n; j++) {
            if (t[i][j]) {
                ert=j;
            }
        }
        pos[i]=ert;
        long long valt=oszt(t[i][ert]);
        for (int j=1; j<=n+1; j++) {
            t[i][j]*=valt, t[i][j]%=mod;
        }
        for (int j=i+1; j<=n; j++) {
            long long spec=t[j][ert];
            for (int k=1; k<=n+1; k++) {
                t[j][k]-=spec*t[i][k];
                t[j][k]%=mod;
            }
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=n; j++) {
            t[i][n+1]-=t[i][j]*sol[j];
            t[i][n+1]%=mod;
        }
        sol[pos[i]]=t[i][n+1];
        sol[pos[i]]+=mod*mod, sol[pos[i]]%=mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        db[a]++, sz[a].push_back(b), s[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!db[i]) {
            q.push(i);
        }
    }
    long long maxi=0;
    while(q.size()>0) {
        int a=q.front();
        q.pop();
        k[a].push_back(-1), k[a].push_back(c);
        for (int i:sz[a]) {
            k[a].push_back(grundy[i]);
        }
        sort(k[a].begin(), k[a].end());
        for (int i=1; i<k[a].size(); i++) {
            if (k[a][i]>k[a][i-1]+1) {
                grundy[a]=k[a][i-1]+1;
                maxi=max(maxi, grundy[a]);
                break;
            }
        }
        for (int i:s[a]) {
            db[i]--;
            if (!db[i]) {
                q.push(i);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        db[grundy[i]]++;
    }
    long long pow=1;
    while(pow<=maxi) {
        pow*=2;
    }
    t[1][pow+1]=1;
    for (int i=0; i<pow; i++) {
        for (int j=0; j<pow; j++) {
            t[i+1][j+1]=-db[i^j];
        }
        t[i+1][i+1]+=n+1;
    }
    gauss_elimination(pow);
    cout << (mod+1-sol[1])%mod << endl;
    return 0;
}