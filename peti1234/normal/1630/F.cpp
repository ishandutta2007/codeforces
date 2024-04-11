#include<bits/stdc++.h>

using namespace std;
const int c=200005, c2=50005;
int szint[c], pos[c], kezd, veg;
vector<pair<int, pair<int, int> > > el;
vector<int> sz[c], ki[c], s[c];
queue<int> q;
void add(int a, int b) {
    //cout << "el " << a << " " << b << "\n";
    ki[a].push_back(sz[b].size()), ki[b].push_back(sz[a].size());
    sz[a].push_back(b), sz[b].push_back(a);
    s[a].push_back(1), s[b].push_back(0);
}
bool bfs() {
    for (int i=kezd; i<=veg; i++) {
        szint[i]=0;
    }
    szint[kezd]=1;
    q.push(kezd);
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
int dfs(int a, int b, int d) {
    if (a==b) {
        return d;
    }
    for (; pos[a]<sz[a].size(); pos[a]++) {
        int x=sz[a][pos[a]], y=s[a][pos[a]];
        if (szint[a]+1==szint[x] && y) {
            int z=dfs(x, b, y);
            if (z) {
                s[a][pos[a]]-=z;
                s[x][ki[a][pos[a]]]+=z;
                return z;
            }
        }
    }
    return 0;
}
int solve() {
    int ans=0;
    while(bfs()) {
        for (int i=kezd; i<=veg; i++) {
            pos[i]=0;
        }
        while(int x=dfs(kezd, veg, 1)) {
            ans+=x;
        }
    }

    for (int i=0; i<=veg; i++) {
        sz[i].clear(), ki[i].clear(), s[i].clear();
    }
    return ans;
}

int w, n, t[c2], h[c2];
vector<int> oszt[c2];


int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c2; i++) {
        for (int j=2*i; j<c2; j+=i) {
            oszt[j].push_back(i);
        }
    }
    cin >> w;
    while (w--) {
        cin >> n;
        kezd=0, veg=4*n+1;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            h[t[i]]=i;
        }
        for (int i=1; i<=n; i++) {
            for (auto x:oszt[t[i]]) {
                if (h[x]) {
                    int s=h[x];
                    add(i, s+2*n), add(i+n, s+3*n);
                }
            }
            add(kezd, i), add(kezd, i+n);
            add(i, i+3*n);
            add(i+2*n, veg), add(i+3*n, veg);
        }
        //cout << "valasz............ ";
        cout << solve()-n << "\n";

        for (int i=1; i<=n; i++) {
            h[t[i]]=0, t[i]=0;
        }
    }
    return 0;
}
/*
1
10
2 3 5 13 14 39 85 154 195 266
*/