#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const ll mod=998244353;
const int N=1010;
int a[N][N];
int b[N][N];
vector<pair<pair<int,int>,pair<int,int> > >ans;
void go(int x1,int y1,int x2,int y2){
    ans.push_back({{x1,y1},{x2,y2}});
    for (int i=x1;i<=x2;i++){
        for (int j=y1;j<=y2;j++){
            b[i][j]=(i+j-x1-y1)%2;
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=c-'0';
            b[i][j]=0;
        }
    }
    if (a[1][1]==1){
        cout<<-1<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=2;j--){
            if (a[i][j]){
                go(i,j-1,i,j);
            }
        }
    }
    for (int i=n;i>=2;i--){
        if (a[i][1]){
            go(i-1,1,i,1);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]!=b[i][j]) exit(1);
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans){
        cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second.first<<" "<<cur.second.second<<endl;
    }
    ans.clear();


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