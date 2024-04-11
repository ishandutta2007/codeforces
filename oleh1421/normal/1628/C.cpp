//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=5010;
int a[N][N];
int b[N][N];
int rec(int x1,int y1,int x2,int y2){
    if (x2-x1+1==0) return 0;
    if (x2-x1+1==2){
        b[x1][y1]=b[x2][y1]=1;
        return a[x1][y1]^a[x1][y2];
    }
    int res=rec(x1+2,y1+2,x2-2,y2-2);
    vector<pair<int,int> >v;
    for (int i=y1;i<y2;i++) v.push_back({x1,i});
    for (int i=x1;i<x2;i++) v.push_back({i,y2});
    for (int i=y2;i>y1;i--) v.push_back({x2,i});
    for (int i=x2;i>x1;i--) v.push_back({i,y1});
    for (int i=0;i<v.size();i++){
        if (i%4<2) {
            res^=a[v[i].first][v[i].second];
            b[v[i].first][v[i].second]=1;
        }
    }
    return res;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cin>>a[i][j],b[i][j]=0;
    }
    cout<<rec(1,1,n,n)<<endl;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            cout<<b[i][j]<<" ";
//        }
//        cout<<endl;
//    }


}

int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
3
c
baa
abc


abc
b
a
**/