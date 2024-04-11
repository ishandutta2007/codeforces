#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef unsigned int uii;
int n,m,q,k,res[100001];
bool bit[1001][1001];
struct cmd {
    int t,i,j;
}c[100001];
vector<int> vec[100001];
void dfs(int u) {
    bool f=false;
    if (!u||c[u].t==4) {
        for (uii i=0;i<vec[u].size();++i) {
            res[vec[u][i]]=res[u];
            dfs(vec[u][i]);
        }
    }
    int x=c[u].i,y=c[u].j;
    if (c[u].t==1) {
        f=bit[x][y];
        if (!bit[x][y]) {
            ++res[u];
            bit[x][y]=true;
        }
        for (uii i=0;i<vec[u].size();++i) {
            res[vec[u][i]]=res[u];
            dfs(vec[u][i]);
        }
        bit[x][y]=f;
    } else if (c[u].t==2) {
        f=bit[x][y];
        if (bit[x][y]) {
            --res[u];
            bit[x][y]=false;
        }
        for (uii i=0;i<vec[u].size();++i) {
            res[vec[u][i]]=res[u];
            dfs(vec[u][i]);
        }
        bit[x][y]=f;
    } else if (c[u].t==3) {
        int t=0;
        for (int j=1;j<=m;++j) {
            if (bit[x][j])
                ++t;
            bit[x][j]^=true;
        }
        res[u]+=(m-t-t);
        for (uii i=0;i<vec[u].size();++i) {
            res[vec[u][i]]=res[u];
            dfs(vec[u][i]);
        }
        for (int j=1;j<=m;++j)
            bit[x][j]^=true;
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
    for (int i=1;i<=q;++i) {
        cin>>c[i].t;
        if (c[i].t<=2) {
            cin>>c[i].i>>c[i].j;
            vec[i-1].push_back(i);
        } else if (c[i].t==3) {
            cin>>c[i].i;
            vec[i-1].push_back(i);
        } else {
        	cin>>k;
            vec[k].push_back(i);
        }
    }
    dfs(0);
    for (int i=1;i<=q;++i)
        cout<<res[i]<<endl;
}