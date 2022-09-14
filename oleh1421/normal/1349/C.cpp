#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000+7;
const int N=1010;
int a[N][N];
int d[N][N];
bool ok[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,t;cin>>n>>m>>t;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            d[i][j]=-1;
        }
    }
    queue<pair<int,int> >q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (i>1 && a[i-1][j]==a[i][j]) d[i][j]=0;
            if (j>1 && a[i][j-1]==a[i][j]) d[i][j]=0;
            if (i<n && a[i+1][j]==a[i][j]) d[i][j]=0;
            if (j<m && a[i][j+1]==a[i][j]) d[i][j]=0;
            if (!d[i][j]) q.push({i,j});
        }
    }
    while (!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if (x>1 && d[x-1][y]==-1){
            d[x-1][y]=d[x][y]+1;
            q.push({x-1,y});
        }
        if (y>1 && d[x][y-1]==-1){
            d[x][y-1]=d[x][y]+1;
            q.push({x,y-1});
        }
        if (x<n && d[x+1][y]==-1){
            d[x+1][y]=d[x][y]+1;
            q.push({x+1,y});
        }
        if (y<m && d[x][y+1]==-1){
            d[x][y+1]=d[x][y]+1;
            q.push({x,y+1});
        }
    }
    while(t--){
        ll x,y,p;cin>>x>>y>>p;
        if (p<=d[x][y] || d[x][y]==-1){
            cout<<a[x][y]<<endl;
        } else {
            cout<<(a[x][y]*1ll+p-d[x][y]*1ll)%2<<endl;
        }
    }

    return 0;
}