#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=502;
int a[N][N];
int r[N][N];
int d[N][N];
int sq[N][N];
int s[N/2][N][N];
//vector<pair
int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            if (c=='R') a[i][j]=1;
            else if (c=='G') a[i][j]=2;
            else if (c=='Y') a[i][j]=3;
            else a[i][j]=4;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j--){
            if (a[i][j]!=a[i][j+1]) r[i][j]=1;
            else r[i][j]=r[i][j+1]+1;
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=n;j>=1;j--){
            if (a[j][i]!=a[j+1][i]) d[j][i]=1;
            else {
                d[j][i]=d[j+1][i]+1;
            }
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=m;j>=1;j--){
            sq[i][j]=min({sq[i+1][j+1]+1,r[i][j],d[i][j]});
        }
    }
    vector<pair<pair<int,int>,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x=sq[i][j];

            if (i+x+x-1>n || j+x+x-1>m) continue;

            if (a[i][j]!=1 || a[i][j+x]!=2 || a[i+x][j]!=3 || a[i+x][j+x]!=4) continue;
            if (sq[i+x][j]>=x && sq[i][j+x]>=x && sq[i+x][j+x]>=x) {
                s[x][i][j]++;
            }
        }
    }
    for (int t=1;t<=min(n,m)/2;t++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++) s[t][i][j]+=s[t][i][j-1];
            for (int j=1;j<=m;j++) s[t][i][j]+=s[t][i-1][j];
        }
    }
    for (int i=1;i<=q;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        x1--;
        y1--;
        for (int d=min(n,m)/2;d>=0;d--){
            x2-=2*d-1;
            y2-=2*d-1;
            if (d==0 || x2>=x1 && y2>=y1 && s[d][x2][y2]-s[d][x1][y2]-s[d][x2][y1]+s[d][x1][y1]>0){
                cout<<(d*d*4)<<endl;
                break;
            }
            x2+=2*d-1;
            y2+=2*d-1;
        }
    }
    return 0;

}