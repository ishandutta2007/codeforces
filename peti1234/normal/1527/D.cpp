#include <bits/stdc++.h>
using namespace std;
const int c=200002, k=20;
long long w, n, ans[c], rf[c], rf2[c], spec, szint[c], fel[c][k];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    rf[a]=1;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            fel[x][0]=a;
            szint[x]=szint[a]+1;
            dfs(x);
            rf[a]+=rf[x], rf2[a]+=rf2[x];
            if (a==1 && rf2[x]) {
                spec=x;
            }
        }
    }
    if (a==2) {
        rf2[a]=rf[a];
    }
}
bool felett(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    return (a==b);
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
            a++, b++;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        szint[1]=1;
        dfs(1);
        for (int x:sz[1]) {
            ans[0]+=rf[x]*(rf[x]-1)/2;
        }
        ans[1]=n*(n-1)/2-ans[0];
        bool baj=0;
        int bal=1, jobb=1;
        for (int i=2; i<=n; i++) {
            if (felett(jobb, i)) {
                if (szint[i]>szint[jobb]) {
                    jobb=i;
                }
            } else if (felett(bal, i) && !felett(spec, i)) {
                if (szint[i]>szint[bal]) {
                    bal=i;
                }
            } else {
                baj=1;
            }
            if (i==n) {
                //cout << "ertekek " << baj << " " << bal << " " << jobb << "\n";
            }
            if (!baj) {
                if (bal==1) {
                    ans[i]=rf[jobb]*(n-rf[spec]);
                } else {
                    ans[i]=rf[jobb]*rf[bal];
                }
            }
        }
        for (int i=1; i<n; i++) {
            ans[i]-=ans[i+1];
        }
        for (int i=0; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

        for (int i=0; i<=n; i++) {
            ans[i]=0, rf[i]=0, rf2[i]=0, v[i]=0;
            sz[i].clear();
            for (int j=0; j<k; j++) {
                fel[i][j]=0;
            }
        }

    }
    return 0;
}
/*
1
4
1 0
2 1
3 1
*/