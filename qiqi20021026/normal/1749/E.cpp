#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dic{{-1,0},{0,-1},{1,0},{0,1}};
vector<pair<int,int>> dic2{{-1,-1},{-1,1},{1,-1},{1,1}};

void solve(){
    int n,m; cin>>n>>m;
    vector<vector<int>> ok(n+2,vector<int>(m+2));
    vector<vector<int>> a(n+2,vector<int>(m+2));
    for (int i=1;i<=n;++i){
        string st; cin>>st;
        for (int j=1;j<=m;++j) a[i][j]=st[j-1]=='#';
    }
    // cerr<<"GG\n";
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i][j]==1) ok[i][j]=1;
            else{
                ok[i][j]=1;
                for (auto [dx,dy]:dic){
                    if (a[i+dx][j+dy]) ok[i][j]=0;
                }
            }
            // cout<<ok[i][j];
        }
        // cout<<'\n';
    }
    // cout<<"GG\n";
    vector<vector<int>> f(n+2,vector<int>(m+2,n*m+1));
    vector<vector<pair<int,int>>> lst(n+2,vector<pair<int,int>>(m+2));
    queue<pair<int,int>> q[2];
    for (int i=1;i<=n;++i){
        if (ok[i][1]){
            f[i][1]=a[i][1]^1;
            q[f[i][1]].push({i,1});
        }
    }
    // cout<<"GG\n";
    while (!q[0].empty()||!q[1].empty()){
        int t=q[0].empty();
        auto [i,j]=q[t].front(); q[t].pop();
        for (auto [dx,dy]:dic2){
            int ni=i+dx,nj=j+dy;
            if (ok[ni][nj]){
                int w=a[ni][nj]^1;
                if (f[ni][nj]>f[i][j]+w){
                    f[ni][nj]=f[i][j]+w;
                    lst[ni][nj]={i,j};
                    q[w].push({ni,nj});
                }
            }
        }
    }
    int mn=0; f[0][m]=n*m+1;
    for (int i=1;i<=n;++i){
        if (ok[i][m]&&f[i][m]<f[mn][m]) mn=i;
    }
    if (mn==0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int x=mn,y=m;
    while (x&&y){
        a[x][y]=1;
        auto [nx,ny]=lst[x][y];
        x=nx; y=ny;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j) cout<<(a[i][j]?'#':'.');
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}