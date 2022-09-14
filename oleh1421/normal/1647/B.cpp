#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const ll mod=998244353;
const int N=1010;
int a[N][N];
bool used[N][N];
void dfs(int x,int y,int &x1,int &y1,int &x2,int &y2,int &cnt){
    x1=min(x1,x);
    x2=max(x2,x);
    y1=min(y1,y);
    y2=max(y2,y);
    cnt++;
    used[x][y]=true;
//    cout<<x<<" "<<y<<endl;
    for (int dx=-1;dx<=1;dx++){
        for (int dy=-1;dy<=1;dy++){
            if (dx && dy) continue;
            if (!dx && !dy) continue;
            if (!used[x+dx][y+dy]){
                dfs(x+dx,y+dy,x1,y1,x2,y2,cnt);
            }
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            used[i][j]=true;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=c-'0';
            used[i][j]=(a[i][j]^1);
//            cout<<used[i][j]<<endl;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (!used[i][j]){
                int x1=n+1,y1=m+1,x2=0,y2=0,cnt=0;
                dfs(i,j,x1,y1,x2,y2,cnt);
                if (cnt!=(x2-x1+1)*(y2-y1+1)){
//                    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<cnt<<endl;
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2121
//121
//2
//
//1 2

/**

R,S

RSAxT
SxART
xSART


**/