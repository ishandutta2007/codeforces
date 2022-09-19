#include <bits/stdc++.h>

using namespace std;
const int c=305;
int n, ut[c], kor[c], par[2*c], pos=1, szindb=1, van[c][c], kell[c][c], ans[c], cnt;
bool v[2*c];
pair<int, int> sor[2*c];
// db[i][j] i hosszu kor es j hosszu ut
bool szin[c];


bool dfs(int a) {
    v[a]=true;
    for (int i=n+1; i<=cnt; i++) {
        if ((ut[a]!=-1 && ut[a]!=sor[i].first) || (kor[a]!=-1 && kor[a]!=sor[i].second) || v[i]) {
            continue;
        }
        v[i]=1;
        if (!par[i] || dfs(par[i])) {
            par[a]=i, par[i]=a;
            return true;
        }
    }
    return false;
}

bool solve() {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            van[i][j]=0, kell[i][j]=0;
        }
    }
    for (int i=1; i<=2*n; i++) {
        par[i]=0;
    }
    for (int i=1; i<=n; i++) {
        int a=ut[i], b=kor[i];
        if (b==-1) {
            continue;
        }
        if (a!=-1) {
            van[b][a]++;
            kell[b][a]=van[b][a];
        }
        if (!kell[b][0]) {
            kell[b][0]++;
        }
    }
    int ossz=0;
    cnt=n;
    for (int i=1; i<=n; i++) {
        for (int j=n; j>=0; j--) {
            if (kell[i][j+1] && !kell[i][j]) {
                kell[i][j]=1;
            }
            if (j==0) {
                while (kell[i][j]%i) {
                    kell[i][j]++;
                }
            }
            if (kell[i][j]) {
                //cout << "fontos " << i << " " << j << " " << kell[i][j] << " " << van[i][j] << "\n";
            }
            ossz+=kell[i][j]-van[i][j];
            if (ossz>n) {
                return 0;
            }
            for (int k=1; k<=kell[i][j]-van[i][j]; k++) {
                cnt++;
                sor[cnt]={j, i};
            }
        }
    }
    int pardb=0;
    for (int i=1; i<=n; i++) {
        if (kor[i]!=-1 && ut[i]!=-1) {
            continue;
        }
        for (int i=1; i<=cnt; i++) {
            v[i]=0;
        }
        //cout << "dfs " << i << "\n";
        pardb+=dfs(i);
    }
    //cout << "parositas " << pardb << "\n";
    if (pardb!=cnt-n) {
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if (par[i]) {
            if (ut[i]==-1) {
                ut[i]=sor[par[i]].first;
            }
            if (kor[i]==-1) {
                kor[i]=sor[par[i]].second;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!par[i] && (ut[i]==-1 || kor[i]==-1)) {
            int a=ut[i], b=kor[i];
            if (b==-1) {
                if (a==-1 || a==0) {
                    kor[i]=1, ut[i]=0;
                } else {
                    kor[i]=kor[pos];
                }
            } else {
                ut[i]=1;
            }
        }
        //cout << "vege " << ut[i] << " " << kor[i] << "\n";
    }

    for (int i=1; i<=n; i++) {
        if (ut[i]!=0) {
            for (int j=1; j<=n; j++) {
                if (kor[i]==kor[j] && ut[j]+1==ut[i]) {
                    ans[i]=j;
                }
            }
        } else {
            int cnt=0, veg=0;
            for (int j=1; j<=i; j++) {
                if (kor[i]==kor[j] && ut[i]==ut[j]) {
                    if (cnt%kor[j]==0) {
                        veg=j;
                    }
                    cnt++;
                }
            }
            if (cnt%kor[i]==0) {
                ans[i]=veg;
            } else {
                for (int j=i+1; j<=n; j++) {
                    if (kor[i]==kor[j] && ut[i]==ut[j]) {
                        ans[i]=j;
                        break;
                    }
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return true;
}

string s;
int cin2() {
    string s;
    cin >> s;
    if (s[0]=='?') {
        return -1;
    }
    int ans=0;
    for (int i=0; i<s.size(); i++) {
        int x=(s[i]-'0');
        ans*=10, ans+=x;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    szin[1]=1;
    for (int i=1; i<=n; i++) {
        ut[i]=cin2(), kor[i]=cin2();
        if (ut[i]>ut[pos]) {
            pos=i;
        }
        if (kor[i]!=-1) {
            if (!szin[kor[i]]) {
                szindb++;
            }
            szin[kor[i]]=1;
        }
        //cout << "ertek " << ut[i] << " " << kor[i] << "\n";
    }
    //cout << "vege " << pos << " " << kor[pos] << " " << szindb << "\n";
    if (szindb>25) {
        cout << -1 << "\n";
        return 0;
    }
    if (kor[pos]!=-1) {
        //cout << "proba\n";
        if (solve()) {
            return 0;
        }
    } else {
        for (int i=1; i<=n; i++) {
            if (szin[i]) {
                kor[pos]=i;
                if (solve()) {
                    return 0;
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}