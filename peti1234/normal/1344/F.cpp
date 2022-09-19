#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int n, k, cnt, ans[c], spec[c];
bool baj;
vector<int> sz[c], id={1, 0, 0, 1}, ry={0, 1, 1, 0}, rb={1, 0, 1, 1}, yb={1, 1, 0, 1};
bitset<c> b[c];
void mul(vector<int> & a, vector<int> b) {
    vector<int> ans={b[0]*a[0]+b[1]*a[2], b[0]*a[1]+b[1]*a[3], b[2]*a[0]+b[3]*a[2], b[2]*a[1]+b[3]*a[3]};
    for (int i=0; i<4; i++) {
        ans[i]%=2;
    }
    a=ans;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        sz[i]=id;
    }
    for (int i=1; i<=k; i++) {
        string s;
        cin >> s;
        int db;
        cin >> db;
        vector<int> p(db);
        for (int i=0; i<db; i++) {
            cin >> p[i];
        }
        if (s=="mix") {
            char c;
            cin >> c;
            int ert=(c=='W' ? 0 :c=='R' ? 1 : (c=='Y' ? 2 : 3));
            cnt++;
            for (auto x:p) {
                b[cnt][2*x-1]=sz[x][0], b[cnt][2*x]=sz[x][1];
            }
            b[cnt][2*n+1]=ert%2;

            cnt++;
            for (auto x:p) {
                b[cnt][2*x-1]=sz[x][2], b[cnt][2*x]=sz[x][3];
            }
            b[cnt][2*n+1]=(ert>=2);
        } else {
            for (auto x:p) {
                mul(sz[x], (s=="RY" ? ry : (s=="RB" ? rb : yb)));
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        int pos=0;
        for (int j=1; j<=2*n+1; j++) {
            if (b[i][j]) {
                pos=j;
                break;
            }
        }
        spec[i]=pos;
        if (!pos) {
            continue;
        }
        if (pos==2*n+1) {
            baj=1;
        }
        for (int j=i+1; j<=cnt; j++) {
            if (b[j][pos]) {
                b[j]^=b[i];
            }
        }
    }

    for (int i=cnt; i>=1; i--) {
        int pos=spec[i];
        bool res=b[i][2*n+1];
        for (int j=1; j<=2*n; j++) {
            if (j!=pos && b[i][j] && ans[j]) {
                res=!res;
            }
        }
        ans[pos]=res;
    }

    if (baj) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            int a=ans[2*i-1]+2*ans[2*i];
            cout << (a==0 ? '.' : a==1 ? 'R' : a==2 ? 'Y' : 'B');
        }
        cout << "\n";
    }

    return 0;
}