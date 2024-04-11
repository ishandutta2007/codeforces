#include <bits/stdc++.h>

using namespace std;
const int c=600005;
int n, m, si[c], cnt, eler[c], ert[c][2], hely;
char bal[c][2], jobb[c][2];
vector<int> sz[c], sor;
bool v[c];
bool dfs(int a) {
    //cout << "dfs " << a << "\n";
    sor.push_back(a);
    v[a]=1;
    eler[a]=++cnt;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            sor.push_back(a);
        } else if (eler[x]>=eler[a]) {
            sor.push_back(x), sor.push_back(a);
        }
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        si[a]++;
        sz[a].push_back(b);
        if (a!=b) {
            si[b]++;
            sz[b].push_back(a);
        }
    }
    n*=2;
    for (int i=1; i<=n; i++) {
        for (auto x:sz[i]) {
            if (si[i]==1 && si[x]==1) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (v[i] || sz[i].size()==0) continue;
        dfs(i);
        sor.pop_back();
        /*cout << "sor: ";
        for (auto x:sor) {
            cout << x << " ";
        }
        cout << "\n";*/
        int len=sor.size(), f=len/2;
        for (int i=0; i<len; i++) {
            if (i<f) ert[hely+i][0]=sor[i];
            else ert[hely+len-1-i][1]=sor[i];
        }
        int veg=hely+f-1;
        for (int i=0; i<f; i+=2) {
            int s=hely+i;
            for (int j=0; j<2; j++) {
                bal[s][j]='L';
                jobb[s][j]='R';
                bal[s+1][j]='R';
                jobb[s+1][j]='L';
            }
        }
        if (f%2==0) {
            jobb[hely][0]='U';
            jobb[hely][1]='D';
            jobb[veg][0]='U';
            jobb[veg][1]='D';
        } else {
            jobb[hely][0]='U';
            jobb[hely][1]='D';
            bal[veg][0]='U';
            bal[veg][1]='D';
        }
        hely+=f;
        sor.clear();
    }
    //return 0;
    n/=2;
    cout << 2 << " " << n << "\n";
    for (int j=0; j<2; j++) {
        for (int i=0; i<n; i++) {
            cout << ert[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int j=0; j<2; j++) {
        for (int i=0; i<n; i++) {
            cout << bal[i][j];
        }
        cout << "\n";
    }

    cout << "\n";

    for (int j=0; j<2; j++) {
        for (int i=0; i<n; i++) {
            cout << jobb[i][j];
        }
        cout << "\n";
    }
    return 0;
}
/*
1
5
1 2 1 3 1 4 1 5
*/