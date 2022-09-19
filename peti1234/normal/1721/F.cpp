#include<bits/stdc++.h>

using namespace std;
const int c=500002;
int szint[c], pos[c], kezd, veg;
bool v[c];
vector<int> sz[c], ki[c], s[c], ert[c];
queue<int> q;
void add(int a, int b, int id) {
    ki[a].push_back(sz[b].size()), ki[b].push_back(sz[a].size());
    sz[a].push_back(b), sz[b].push_back(a);
    ert[a].push_back(id), ert[b].push_back(id);
    s[a].push_back(1), s[b].push_back(0);
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
    for (; pos[a]<sz[a].size(); pos[a]++) {
        int x=sz[a][pos[a]], y=s[a][pos[a]];
        if (szint[a]+1==szint[x] && y) {
            int z=dfs(x, y);
            if (z) {
                s[a][pos[a]]-=z;
                s[x][ki[a][pos[a]]]+=z;
                return z;
            }
        }
    }
    return 0;
}
void dfs2(int a) {
    //cout << "dfs2 " << a << "\n";
    v[a]=true;
    int si=sz[a].size();
    for (int i=0; i<si; i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x] && y) {
            dfs2(x);
        }
    }
}
int dinic() {
    int ans=0;
    while(bfs()) {
        for (int i=kezd; i<=veg; i++) {
            pos[i]=0;
        }
        while(int x=dfs(kezd, 1)) {
            ans+=x;
        }
    }
    return ans;
}

int n1, n2, m, w, cnt;
long long ss;
vector<long long> sum;
vector<int> rem, elek;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n1 >> n2 >> m >> w;
    kezd=0, veg=n1+n2+1;
    for (int i=1; i<=n1; i++) {
        add(kezd, i, 0);
    }
    for (int i=n1+1; i<=n1+n2; i++) {
        add(i, veg, 0);
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        b+=n1;
        add(a, b, i);
    }
    cnt=dinic();
    dfs2(kezd);
    sum.push_back(0), rem.push_back(0), elek.push_back(0);
    for (int i=1; i<=n1; i++) {
        if (!v[i]) {
            //cout << "fontos " << i << "\n";
            int si=sz[i].size();
            for (int j=0; j<si; j++) {
                int x=sz[i][j], suly=s[i][j], id=ert[i][j];
                if (x!=kezd && suly==0) {
                    ss+=id;
                    sum.push_back(ss), rem.push_back(i), elek.push_back(id);
                }
            }
        }
    }
    for (int i=n1+1; i<=n1+n2; i++) {
        if (v[i]) {
            //cout << "fontos " << i << "\n";
            int si=sz[i].size();
            for (int j=0; j<si; j++) {
                int x=sz[i][j], suly=s[i][j], id=ert[i][j];
                if (x!=veg && suly==1) {
                    ss+=id;
                    sum.push_back(ss), rem.push_back(n1-i), elek.push_back(id);
                }
            }
        }
    }
    while (w--) {
        int x;
        cin >> x;
        if (x==1) {
            cout << 1 << "\n";
            cout << rem.back() << "\n";
            rem.pop_back(), sum.pop_back(), elek.pop_back();
            cout << sum.back();
        }
        if (x==2) {
            int si=elek.size();
            cout << si-1 << "\n";
            for (int i=1; i<si; i++) {
                cout << elek[i] << " ";
            }
        }
        cout << "\n\n\n";
        cout.flush() << endl;
    }
    return 0;
}
/*
5 5 7 5
1 1 2 1 3 2
4 3 4 4 4 5
5 5
*/