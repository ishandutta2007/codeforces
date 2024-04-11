#include <bits/stdc++.h>

using namespace std;
const int c=42, k=8, c2=(1<<20);
int n, m, szint[c];
long long elm[c], po[c], ans[k], akt[k];
bool el[c][c], v[c], pkor;
int maskdb[c2], jodb[c2];
vector<int> sz;
void dfs(int a) {
    v[a]=true;
    sz.push_back(a);
    for (int i=1; i<=n; i++) {
        if (el[a][i] && !v[i]) {
            szint[i]=szint[a]+1;
            dfs(i);
        }
        if (el[a][i] && ((szint[a]%2) == (szint[i]%2))) {
            pkor=1;
        }
    }
}
int main()
{
    cin >> n >> m;
    po[0]=1;
    for (int i=1; i<=n; i++) {
        po[i]=po[i-1]*2;
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        el[a][b]=1, el[b][a]=1;
        elm[a]+=po[b], elm[b]+=po[a];
    }
    ans[0]=1;
    for (int cs=1; cs<=n; cs++) {
        if (v[cs]) {
            continue;
        }
        pkor=0;
        dfs(cs);
        int si=sz.size(), fel=si/2, m1=(1<<fel), m2=(1<<(si-fel));
        for (int i=0; i<k; i++) {
            akt[i]=0;
        }
        if (si==1) {
            akt[0]=2;
        } else {
            for (int i=0; i<m2; i++) {
                maskdb[i]=0, jodb[i]=0;
            }
            for (int mask=0; mask<m1; mask++) {
                long long res=0;
                bool baj=0;
                for (int i=0; i<fel; i++) {
                    if (mask & (1<<i)) {
                        if (res & po[sz[i]]) {
                            baj=1;
                        }
                        res=(res | elm[sz[i]]);
                    }
                }
                if (!baj) {
                    int marad=m2-1;
                    for (int i=fel; i<si; i++) {
                        if (res & po[sz[i]]) {
                            marad-=(1<<(i-fel));
                        }
                    }
                    maskdb[marad]++;
                }
            }

            for (int mask=0; mask<m2; mask++) {
                long long res=0;
                bool baj=0;
                for (int i=fel; i<si; i++) {
                    if (mask & (1<<(i-fel))) {
                        if (res & po[sz[i]]) {
                            baj=1;
                        }
                        res=(res | elm[sz[i]]);
                    }
                }
                if (!baj) {
                    jodb[mask]++;
                }
            }

            for (int i=0; i<si-fel; i++) {
                for (int j=0; j<m2; j++) {
                    if ((j & po[i])==0) {
                        jodb[j+po[i]]+=jodb[j];
                    }
                }
            }

            long long sum=0;
            for (int i=0; i<m2; i++) {
                sum+=maskdb[i]*jodb[i];
            }
            sum--;
            akt[1]=akt[4]=1;
            if (!pkor) {
                sum-=2;
                akt[2]=2;
            }
            akt[3]=akt[6]=sum;
            akt[7]=po[si];
            for (int i=0; i<7; i++) {
                akt[7]-=akt[i];
            }
        }
        for (int pos=7; pos>=0; pos--) {
            long long ert=0;
            for (int i=0; i<k; i++) {
                for (int j=0; j<k; j++) {
                    if ((i|j) == pos) {
                        ert+=ans[i]*akt[j];
                    }
                }
            }
            ans[pos]=ert;
        }
        sz.clear();
    }
    cout << ans[7] << "\n";
    return 0;
}