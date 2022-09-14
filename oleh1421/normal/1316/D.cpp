#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=1010;
vector<pair<int,int> >g[N][N];
int a[N][N];
int b[N][N];
bool ok[N][N];
char ans[N][N];
bool used[N][N];
int n;
int cnt=0;
vector<pair<int,int> >order;
void dfs(int i,int j){
    used[i][j]=true;
    cnt++;
    for (int dx=-1;dx<=1;dx++){
        for (int dy=-1;dy<=1;dy++){
            if (dx && dy) continue;
            if (!dx && !dy) continue;
            int tox=i+dx;
            int toy=j+dy;
            if (tox>n || toy>n || tox<1 || toy<1) continue;
            if (used[tox][toy] || !ok[tox][toy]) continue;
            if (dx==-1){
                ans[tox][toy]='D';
            } else if (dx==1){
                ans[tox][toy]='U';
            } else if (dy==-1){
                ans[tox][toy]='R';
            } else {
                ans[tox][toy]='L';
            }
            dfs(tox,toy);
        }
    }
}
pair<int,int>get(int x,int y){
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) used[i][j]=false;
    while (ans[x][y]!='X'){
        used[x][y]=true;
        if (ans[x][y]=='L') y--;
        else if (ans[x][y]=='R') y++;
        else if (ans[x][y]=='D') x++;
        else x--;
        if (!x || !y || x>n || y>n) exit(1);
        if (used[x][y]) return {-1,-1};
    }
    return {x,y};
}
void solve(){
    cin>>n;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x,y;cin>>x>>y;
            a[i][j]=x;
            b[i][j]=y;
            if (x==-1 && y==-1){
                v.push_back({i,j});
            } else g[x][y].push_back({i,j});
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]==-1 && b[i][j]==-1) continue;
            if (g[i][j].empty()) continue;
            for (auto x:g[i][j]){
                ok[x.first][x.second]=true;
            }
            if (!ok[i][j]){
                cout<<"INVALID\n";
                return;
            }
            cnt=0;
            ans[i][j]='X';
            dfs(i,j);
            if (cnt!=g[i][j].size()){
                cout<<"INVALID\n";
                return;
            }
            for (auto x:g[i][j]){
                ok[x.first][x.second]=false;
                used[x.first][x.second]=false;
            }
        }
    }
    for (auto cur:v){
        int x=cur.first;
        int y=cur.second;
        ok[x][y]=true;
    }
    for (auto cur:v){
        int x=cur.first;
        int y=cur.second;
        if (used[x][y]) continue;
        cnt=0;
        dfs(x,y);
        if (cnt==1){
            cout<<"INVALID\n";
            return;
        }
        if (ok[x][y-1]) ans[x][y]='L';
        else if (ok[x][y+1]) ans[x][y]='R';
        else if (ok[x-1][y]) ans[x][y]='U';
        else ans[x][y]='D';
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ans[i][j]=='L' && j-1<1){
                cout<<"INVALID\n";
                return;
            }
            if (ans[i][j]=='R' && j+1>n){
                cout<<"INVALID\n";
                return;
            }
            if (ans[i][j]=='U' && i-1<1){
                cout<<"INVALID\n";
                return;
            }
            if (ans[i][j]=='D' && i+1>n){
                cout<<"INVALID\n";
                return;
            }
            if (ans[i][j]!='X' && ans[i][j]!='L' && ans[i][j]!='R' && ans[i][j]!='D' && ans[i][j]!='U'){
                cout<<"INVALID\n";
                return;
            }
//            if (a[i][j]!=cur.first || b[i][j]!=cur.second) exit(1);
        }
    }
    cout<<"VALID\n";
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cout<<ans[i][j];
        cout<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}