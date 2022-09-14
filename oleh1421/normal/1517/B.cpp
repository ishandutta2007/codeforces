#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=210;
const ll mod=1000000007;
int a[N][N];
int pos[N][N];
bool need[N][N];
bool used[N];
void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=m;i++) used[i]=false;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            need[i][j]=false;
            cin>>a[i][j];
            v.push_back({a[i][j],{i,j}});
        }
    }
    sort(v.begin(),v.end());
    for (int i=0;i<m;i++){
        need[v[i].second.first][v[i].second.second]=true;
    }
    for (int i=1;i<=n;i++){
        vector<pair<int,int> >x,y;
        for (int j=1;j<=m;j++){
            x.push_back({used[j],j});
            y.push_back({need[i][j],a[i][j]});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        reverse(y.begin(),y.end());
        for (int j=0;j<m;j++){
            a[i][x[j].second]=y[j].second;
//            cout<<y[j].second<<" ";
            used[x[j].second]|=y[j].first;
        }
//        cout<<endl;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }

}
int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 9 7
...##....
..#.##..#
..#....##
.##...#..
....#....
W
**/

/**
3 2 3
3 3
2 2
1 1
**/