#include<bits/stdc++.h>

using namespace std;
const int c=500002;
int szint[c], pos[c], kezd, veg;
bool v[c];
vector<int> sz[c], ki[c], s[c];
queue<int> q;
void add(int a, int b, int s1, int s2) {
    //cout << "add " << a << " " << b << " " << s1 << " " << s2 << "\n";
    ki[a].push_back(sz[b].size()), ki[b].push_back(sz[a].size());
    sz[a].push_back(b), sz[b].push_back(a);
    s[a].push_back(s1), s[b].push_back(s2);
}
bool bfs() {
    for (int i=kezd; i<=veg; i++) {
        szint[i]=0;
    }
    szint[0]=1;
    q.push(0);
    while(q.size()>0) {
        int a=q.front();
        q.pop();
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i], y=s[a][i];
            if (y && !szint[x]) {
                szint[x]=szint[a]+1;
                q.push(x);
            }
        }
    }
    return szint[veg];
}
int dfs(int a, int d) {
    if (a==veg) {
        return d;
    }
    int sum=0;
    for (; pos[a]<sz[a].size(); pos[a]++) {
        int x=sz[a][pos[a]], y=s[a][pos[a]];
        if (szint[a]+1==szint[x] && y) {
            int z=dfs(x, min(y, d-sum));
            if (z) {
                s[a][pos[a]]-=z;
                s[x][ki[a][pos[a]]]+=z;
                sum+=z;
            }
        }
    }
    return sum;
}
int dinic() {
    int ans=0;
    while(bfs()) {
        for (int i=kezd; i<=veg; i++) {
            pos[i]=0;
        }
        while(int x=dfs(kezd, c)) {
            ans+=x;
        }
    }
    return ans;
}

int n, m, spec, fix[c], val[c], si[c], hely[c];
long long smin, spl;
set<int> el[c];
void dfs2(int a) {
    if (el[a].size()==0) return;
    auto it=(el[a].begin());
    int x=*it;
    el[a].erase(x), el[x].erase(a);
    cout << a << " " << x << "\n";
    dfs2(x);
}
int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    kezd=0, veg=n+2, spec=n+1;
    for (int i=1; i<=n; i++) cin >> fix[i];
    for (int i=1; i<=n; i++) {
        cin >> val[i];
        if (val[i]<0) add(kezd, i, -val[i], 0), smin-=val[i];
        if (val[i]>0) add(i, veg, val[i], 0), spl+=val[i];
        if (!fix[i]) add(i, spec, c, c);
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        si[a]++, si[b]++;
        add(a, b, 1, 1);
    }
    for (int i=1; i<=n; i++) {
        if (fix[i] && (si[i]+val[i])%2) {
            cout << "NO\n";
            return 0;
        }
    }
    if (abs(smin>m) || abs(spl)>m) {
        cout << "NO\n";
        return 0;
    }
    add(kezd, spec, c-smin, 0);
    add(spec, veg, c-spl, 0);

    int x=dinic();
    if (x!=c) {
        cout << "NO\n";
        return 0;
    }


    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        int h=sz[i].size();
        for (int j=0; j<h; j++) {
            int x=sz[i][j], suly=s[i][j];
            if (1<=x && x<=n) {
                //cout << "fontos " << i << " " << x << " " << suly << "\n";
                if (suly==0) {
                    cout << i << " " << x << "\n";
                }
                if (suly==1) {
                    el[i].insert(x);
                    el[x].insert(i);
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        int db=el[i].size();
        if (db%2) {
            dfs2(i);
        }
    }
    for (int i=1; i<=n; i++) {
        dfs2(i);
    }

    return 0;
}
/*
5 5 7 5
1 1 2 1 3 2
4 3 4 4 4 5
5 5
*/