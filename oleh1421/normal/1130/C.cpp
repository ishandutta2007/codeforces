#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
bool a[61][61];
int used[61][61];
int r1,c1,r2,c2;
void dfs(int vx,int vy,int t){
    if (a[vx][vy]==0) return;
    if (used[vx][vy]) return;
    used[vx][vy]=t;
    dfs(vx+1,vy,t);
    dfs(vx-1,vy,t);
    dfs(vx,vy+1,t);
    dfs(vx,vy-1,t);
}
int main(){

    cin>>n;
    cin>>r1>>c1>>r2>>c2;
    for (int i=1;i<=n;i++){
        string s;cin>>s;
        for (int j=1;j<=n;j++){
            a[i][j]=(1+int(s[j-1])-int('0'))%2;
        }
    }
    //for (int i=1;i<=)
    int timer=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (!used[i][j] && a[i][j]){
                dfs(i,j,++timer);
            }
        }
    }
    vector<pair<int,int> >u;
    vector<pair<int,int> >v;
    if (used[r1][c1]==used[r2][c2]){
        cout<<0;
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]){
            if (used[i][j]==used[r1][c1]) u.push_back({i,j});
            if (used[i][j]==used[r2][c2]) v.push_back({i,j});
            }
        }
    }
    int minx=100000001;
    for (auto cur1:u){
        for (auto cur2:v){
            minx=min(minx,(cur1.first-cur2.first)*(cur1.first-cur2.first)+(cur1.second-cur2.second)*(cur1.second-cur2.second));
        }
    }
    cout<<minx;
    return 0;
}