#include <bits/stdc++.h>

using namespace std;


const int c=2002;
int kezd, veg, pos[c], szint[c];
long long sok=1e14;
vector<int> sz[c], ki[c];
vector<long long> s[c];
void add(int a, int b, long long c) {
    ki[a].push_back(sz[b].size()), ki[b].push_back(sz[a].size());
    sz[a].push_back(b), sz[b].push_back(a);
    s[a].push_back(c), s[b].push_back(0);
}
long long dfs(int a, long long ert) {
    //cout << "dfs " << a << " " << ert << endl;
    if (a==veg) {
        return ert;
    }
    for (; pos[a]<sz[a].size(); pos[a]++) {
        int x=sz[a][pos[a]];
        long long suly=s[a][pos[a]];
        if (szint[x]==szint[a]+1 && suly) {
            long long add=dfs(x, min(ert, suly));
            if (add) {
                s[a][pos[a]]-=add;
                s[x][ki[a][pos[a]]]+=add;
                return add;
            }
        }
    }
    return 0;
}
bool bfs() {
    for (int i=kezd; i<=veg; i++) {
        szint[i]=0;
    }
    szint[kezd]=1;
    queue<int> q;
    q.push(kezd);
    while(q.size()>0) {
        int a=q.front();
        q.pop();
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i];
            long long suly=s[a][i];
            if (suly && !szint[x]) {
                szint[x]=szint[a]+1;
                q.push(x);
            }
        }
    }
    return szint[veg];
}
long long dinic() {
    long long ans=0;
    while(bfs()) {
        for (int i=kezd; i<=veg; i++) {
            pos[i]=0;
        }
        while(long long add=dfs(kezd, sok)) {
            ans+=add;
        }
    }
    return ans;
}


int x[c], y[c], ert[c], suly[c], n;
long long sum;


int main()
{
    cin >> n;
    veg=2*n+1;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i] >> suly[i];
        swap(x[i], y[i]);

        sum+=suly[i];
        if (x[i]%2==0) {
            ert[i]=2-(bool)(y[i]%2);
        } else {
            ert[i]=3+(bool)(y[i]%2);
        }
        //cout << "ert ";
        //cout << i << " " << ert[i] << "\n";
    }
    for (int i=1; i<=n; i++) {
        add(i+n, i, suly[i]);
        if (ert[i]==1) {
            add(kezd, i+n, sok);
        }
        if (ert[i]==4) {
            add(i, veg, sok);
        }
        for (int j=1; j<=n; j++) {
            if (i==j) {
                continue;
            }
            if (max(abs(x[i]-x[j]), abs(y[i]-y[j]))==1 && ert[j]==ert[i]+1) {
                //cout << "spec " << i << " " << j << "\n";
                add(i, j+n, sok);
            }
        }
    }
    cout << sum-dinic() << "\n";
    return 0;
}
/*
4
0 0 4
0 1 5
1 0 3
-1 1 2
*/