#include <bits/stdc++.h>

using namespace std;
vector<int> sz[200001];
vector<int> s[200001];
int n;
long long sum;
int comp[200001];
int ecomp[200001];
bool v[200001];
bool o[200001];
dfs(int a)
{
    o[a]=false;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        int y=s[a][i];
        if (y==0 && o[x]) {
            comp[x]=comp[a];
            dfs(x);
        }
    }
}
int  dfs(int a, int k)
{
    int sum=comp[a];
    int ans=1;
    if (k==0) {
        comp[a]=1;
    }
    if (k==1) {
        v[a]=true;
    }
    o[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        int y=s[a][i];
        if (k==1 && y==1 && !v[x]) {
            int b=dfs(x, 1);
            //comp[a]+=com[x];
            sum+=ecomp[x];
            ans+=b;
        }
        if (y==0 && k==0 && !o[x]) {
            int b=dfs(x, 0);
            comp[a]+=comp[x];
        }
    }
    ecomp[a]=sum;
    return ans;
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b);
        sz[b].push_back(a);
        s[a].push_back(c);
        s[b].push_back(c);
    }
    vector<int> p;
    for (int i=1; i<=n; i++) {
        if (!o[i]) {
            dfs(i, 0);
            p.push_back(i);
        }
    }
    for (int i=0; i<p.size(); i++) {
        int a=p[i];
        dfs(a);
    }
    /*for (int i=1; i<=n; i++) {
        cout << comp[i] << " " << endl;
    }*/
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            long long a=dfs(i, 1);
            sum+=(ecomp[i]-1)*a;
        }
    }
    /*for (int i=1; i<=n; i++) {
        cout << ecomp[i] << " ";
    }*/
    cout << sum << endl;
    return 0;
}