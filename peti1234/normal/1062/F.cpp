#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, m, ans;
vector<int> sz[c][2];
int be[c], fel[c], tav[c], utveg;
queue<int> q;
vector<int> ut, ut2, ut3;
int hely[c][2], kom[c];
bool v[c][2];
bool jo[c];
void dfs(int a, int s, int ki) {
    v[a][s]=true, hely[a][s]=ki;
    for (int x:sz[a][s]) {
        if (!v[x][s]) {
            dfs(x, s, ki);
        }
    }
}
void solve(vector<int> sor) {
    int si=sor.size();
    for (int i=1; i<=n; i++) {
        hely[i][0]=0, hely[i][1]=si+1;
        v[i][0]=0, v[i][1]=0, kom[i]=0;
    }
    for (int i=0; i<si; i++) {
        int kezd=sor[i];
        dfs(kezd, 1, i+1);
    }
    for (int i=si-1; i>=0; i--) {
        int veg=sor[i];
        dfs(veg, 0, i+1);
    }
    for (int x:sor) {
        hely[x][0]=si, hely[x][1]=si+1;
    }
    for (int i=1; i<=n; i++) {
        kom[hely[i][0]+1]++, kom[hely[i][1]]--;
    }
    for (int i=1; i<=si; i++) {
        kom[i]+=kom[i-1];
        if (kom[i]<=1) {
            jo[sor[i-1]]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a][0].push_back(b);
        sz[b][1].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        be[i]=sz[i][1].size();
        if (!be[i]) {
            q.push(i);
        }
    }
    while (q.size()>0) {
        int a=q.front(), opt=0;
        q.pop();
        for (int x:sz[a][1]) {
            if (tav[x]>=tav[opt]) {
                opt=x;
            }
        }
        fel[a]=opt, tav[a]=tav[opt]+1;
        if (tav[a]>tav[utveg]) {
            utveg=a;
        }
        for (int x:sz[a][0]) {
            be[x]--;
            if (!be[x]) {
                q.push(x);
            }
        }
    }
    while (utveg) {
        ut.push_back(utveg);
        utveg=fel[utveg];
    }
    reverse(ut.begin(), ut.end());
    ut2=ut, ut3=ut;
    solve(ut);
    for (int i=1; i<=n; i++) {
        int pos=hely[i][0];
        if (pos+2==hely[i][1]) {
            if (pos%2) {
                ut2[pos]=i;
            } else {
                ut3[pos]=i;
            }
        }
    }
    solve(ut2), solve(ut3);
    for (int i=1; i<=n; i++) {
        ans+=jo[i];
    }
    cout << ans << "\n";
    return 0;
}