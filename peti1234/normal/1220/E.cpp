#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, os[c], db[c], k;
vector<int> sz[200001], mod[c];
long long s[200001], sum;
bool v[c];
void unio(int a, int b)
{
    s[a]+=s[b];
    os[b]=a;
    s[b]=0;
}
bool dfs(int a)
{
    if (a==k) {
        sum+=s[a];
        s[a]=0;
        return true;
    }
    v[a]=true;
    bool c=false;
    for (int i=0; i<mod[a].size(); i++) {
        int x=mod[a][i];
        if (!v[x]) {
            c=dfs(x);
            if (c) {
                sum+=s[a];
                s[a]=0;
                return true;
            }
        }
    }
    return false;
}
long long ker(int a)
{
    long long ans=s[a];
    v[a]=true;
    long long maxi=0;
    for (int i=0; i<mod[a].size(); i++) {
        int x=mod[a][i];
        if (!v[x]) {
            maxi=max(maxi, ker(x));
        }
    }
    return ans+maxi;
}
long long modker(int a)
{
    long long ans=s[a];
    v[a]=true;
    long long maxi=0;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            maxi=max(maxi, modker(x));
        }
    }
    return ans+maxi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        os[i]=i;
        cin >> s[i];
    }
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        sz[x].push_back(y);
        sz[y].push_back(x);
    }
    if (m==n-1) {
        cin >> k;
        cout << modker(k) << endl;
        return 0;
    }
    queue<int> q;
    for (int i=1; i<=n; i++) {
        db[i]=sz[i].size();
        if (db[i]==1) {
            q.push(i);
        }
    }
    while(q.size()>0) {
        int a=q.front();
        q.pop();
        v[a]=true;
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i];
            db[x]--;
            if (db[x]==1) {
                q.push(x);
            }
        }
    }
    cin >> k;
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            os[i]=0;
            s[0]+=s[i];
            s[i]=0;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            os[i]=0;
            s[0]+=s[i];
            for (int j=0; j<sz[i].size(); j++) {
                int x=sz[i][j];
                if (v[x]) {
                    mod[0].push_back(x);
                }
            }
        } else {
            for (int j=0; j<sz[i].size(); j++) {
                int x=os[sz[i][j]];
                mod[i].push_back(x);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        v[i]=0;
    }
    if (os[k]!=0) {
        dfs(0);
    }
    for (int i=0; i<=n; i++) {
        v[i]=0;
    }
    cout << sum+ker(0);
    return 0;
}