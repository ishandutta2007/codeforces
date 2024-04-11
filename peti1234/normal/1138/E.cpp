#include <bits/stdc++.h>

using namespace std;
int n, m, d;
int dp[100001][51];
int apa[100001];
vector<int> os[100001];
vector<int> sz[100001];
vector<int> inv[100001];
bool op[100001][51];
bool l[100001][51];
bool q[100001];
vector<int> p;
int f=1000000;
void dfs(int a)
{
    q[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!q[x]) {
            dfs(x);
        }
    }
    p.push_back(a);
}
void invdfs(int a, int b)
{
    q[a]=false;
    apa[a]=b;
    os[b].push_back(a);
    for (int i=0; i<inv[a].size(); i++) {
        int x=inv[a][i];
        if (q[x]) {
            invdfs(x, b);
        }
    }
}
void comp(int a)
{
    queue<pair<int, int> >q;
    q.push({a, 0});
    while(q.size()>0) {
        int fi=q.front().first;
        int se=q.front().second;
        q.pop();
        if (!l[fi][se]) {
            l[fi][se]=true;
            for (int i=0; i<sz[fi].size(); i++) {
                int x=sz[fi][i];
                if (apa[fi]==apa[x]) {
                    if (!l[x][(se+1)%d]) {
                        q.push({x, (se+1)%d});
                    }
                }
            }
        }
    }
}
int solve(int a, int b)
{
    //cout << a << " " << b << endl;
    if (dp[a][b]!=0) {
        return dp[a][b]-f;
    }
    int ans=0;
    if (apa[a]!=a) {
        for (int i=0; i<d; i++) {
            if (l[a][i]) {
                ans=solve(apa[a], (b-i+d)%d);
                break;
            }
        }
        dp[a][b]=ans+f;
        return ans;
    }
    for (int i=0; i<os[a].size(); i++) {
        for (int j=0; j<d; j++) {
            int x=os[a][i];
            //cout << " " << x << " " << j << "\n";
            //cout << x << " " << op[x][j] << " " << l[x][(j+b)%d]  << "\n";
            //cout << j << " " << (j+b)%d << " " <<  "\n";
            if (l[x][j] && op[x][(j+b)%d]) {
                ans++;
                break;
            }
        }
    }
    int maxi=0;
    for (int i=0; i<os[a].size(); i++) {
        int x=os[a][i];
        for (int j=0; j<sz[x].size(); j++) {
            int y=sz[x][j];
            if (apa[x]!=apa[y]) {
                for(int k=0; k<d; k++) {
                    if (l[x][k]) {
                        maxi=max(maxi, solve(y, (b+k+1)%d));
                    }
                }
            }
        }
    }
    dp[a][b]=ans+maxi+f;
    return ans+maxi;
}
int main()
{
    cin >> n >> m >> d;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        inv[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<d; j++) {
            op[i][j]=(s[j]=='1');
        }
    }
    for (int i=1; i<=n; i++) {
        if(!q[i]) {
            dfs(i);
        }
    }
    for (int i=n-1; i>=0; i--) {
        if (q[p[i]]) {
            invdfs(p[i], p[i]);
        }
    }
    /*for (int i=1; i<=n; i++) {
        cout << os[i].size() << "\n";
        for (int j=0; j<os[i].size(); j++) {
            cout << os[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i=1; i<=n; i++) {
        if (apa[i]==i) {
            comp(i);
        }
    }
    /*for (int i=1; i<=n; i++) {
        for (int j=0; j<d; j++) {
            cout << l[i][j];
        }
        cout << "\n";
    }*/
    cout << solve(1, 0);
    return 0;
}
/*
10 9 3
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
100
010
001
100
010
001
100
010
001
100
*/