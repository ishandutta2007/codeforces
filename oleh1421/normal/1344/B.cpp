#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
int a[N][N];
bool used[N][N];
void dfs(int x,int y){
    if (used[x][y]) return;
    if (!a[x][y]) return;
    used[x][y]=true;
    for (int dx=-1;dx<=1;dx++){
        for (int dy=-1;dy<=1;dy++){
            if (!dx && !dy) continue;
            if (dx && dy) continue;
            dfs(x+dx,y+dy);
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    int cnt=0;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            a[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='#');
            cnt+=a[i][j];
        }
    }
    if (cnt==0){
        cout<<0<<endl;
        return;
    }
    int row=0;
    for (int i=1;i<=n;i++){
        int cnt=0;
        for (int j=1;j<=m;j++){
            if (a[i][j] && !a[i][j-1] && cnt){
                cout<<-1<<endl;
                return;
            }
            cnt+=a[i][j];

        }
        if (!cnt){
            row=1;
        }
    }
    int col=0;
    for (int i=1;i<=m;i++){
        int cnt=0;
        for (int j=1;j<=n;j++){
            if (a[j][i] && !a[j-1][i] && cnt){
                cout<<-1<<endl;
                return;
            }
            cnt+=a[j][i];
        }
        if (!cnt){
            col=1;
        }
    }
    if (col+row==1){
        cout<<-1<<endl;
        return;
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            used[i][j]=false;
        }
    }
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (used[i][j]) continue;
            if (!a[i][j]) continue;
            res++;
            dfs(i,j);
        }
    }
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}