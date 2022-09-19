#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, maxi, szint[c], szintdb[c], leveldb[c], csop[c], cnt, elso[c], csopmeret[c];
vector<int> sz[c], ossz[c], invszint[c];
bool v[c], ans[c], sol[c];
void dfs(int a) {
    v[a]=true;
    invszint[szint[a]].push_back(a);
    szintdb[szint[a]]++;
    if (sz[a].size()==0) {
        leveldb[szint[a]]++;
    }
    maxi=max(maxi, szint[a]);
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=2; i<=n; i++) {
        int a; cin >> a;
        sz[a].push_back(i);
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=maxi; i++) {
        ossz[szintdb[i]].push_back(i);
    }
    for (int i=1; i<=m; i++) {
        elso[i]=n+1;
    }
    for (int i=1; i<=n; i++) {
        int si=ossz[i].size(), pt=0, ert=1;
        while (pt<si) {
            cnt++;
            int kov=pt+ert, mennyi=0;
            for (; pt<min(kov, si); pt++) {
                csop[ossz[i][pt]]=cnt;
                mennyi+=i;
            }
            ert*=2;
            csopmeret[cnt]=mennyi;
            //cout << "csoport " << mennyi << " " << cnt << endl;
            for (int i=m; i>=0; i--) {
                if (elso[i]<=n) {
                    elso[i+mennyi]=min(elso[i+mennyi], cnt);
                }
            }
        }
    }
    if (elso[m]>n) {
        cout << maxi+1 << "\n";
        int mm=m;
        for (int i=1; i<=maxi; i++) {
            if (mm>=szintdb[i]) {
                mm-=szintdb[i];
                for (int j:invszint[i]) {
                    ans[j]=1;
                }
            } else if (mm>=szintdb[i]-leveldb[i]) {
                mm-=szintdb[i]-leveldb[i];
                for (int j:invszint[i]) {
                    if (sz[j].size()>0) {
                        ans[j]=1;
                    } else if (mm) {
                        mm--, ans[j]=1;
                    }
                }
            }
        }
    } else {
        cout << maxi << "\n";
        int mm=m;
        for (int i=cnt; i>=1; i--) {
            if (mm>=csopmeret[i] && elso[mm-csopmeret[i]]<=n) {
                //cout << "valt " << i << endl;
                sol[i]=1;
                mm-=csopmeret[i];
            }
        }
        for (int i=1; i<=n; i++) {
            ans[i]=sol[csop[szint[i]]];
        }
    }
    for (int i=1; i<=n; i++) {
        if (ans[i]) {
            cout << 'a';
        } else {
            cout << 'b';
        }
    }
    cout << "\n";
    return 0;
}
/*
13 2
1 1 1
2 2 2
2 2 2
3 3 3
*/