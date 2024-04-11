#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[3000001];
int a, b, c;
vector<int> sz[3000001];
vector<int> s[3000001];
vector<int> szsz[3000001];
vector<int> ss[3000001];
bool v[3000001];
int fsz[3000001];
vector<int> jj;
void mely(int a)
{
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        if (!v[sz[a][i]]) {
            int x=sz[a][i];
            szsz[a].push_back(x);
            szsz[x].push_back(a);
            ss[a].push_back(s[a][i]);
            ss[x].push_back(s[a][i]);
            fsz[a]++;
            fsz[x]++;
            mely(x);
        }
    }
}
void tor(int a)
{
    fsz[a]=0;
    v[a]=false;
    for (int i=0; i<szsz[a].size(); i++) {
        int x=szsz[a][i];
        if (v[x]) {
            if (t[a]==1) {
                t[x]++;
                t[x]%=2;
                jj.push_back(ss[a][i]);
            }
            fsz[x]--;
            if (fsz[x]==1) {
                tor(x);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]==-1) {
            a++;
        }
        if (t[i]==0) {
            b++;
        }
        if (t[i]==1) {
            c++;
        }
    }
    if (a==0 && c%2!=0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if (t[i]==-1) {
            if (c%2!=0) {
                t[i]=1;
                c++;
            } else {
                t[i]=0;
            }
        }
    }
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        sz[x].push_back(y);
        sz[y].push_back(x);
        s[x].push_back(i);
        s[y].push_back(i);
    }
    mely(1);
    for (int i=1; i<=n; i++) {
        if (fsz[i]==1) {
            tor(i);
        }
    }
    cout << jj.size() << endl;
    for (int i=0; i<jj.size(); i++) {
        cout << jj[i] << endl;
    }
    return 0;
}