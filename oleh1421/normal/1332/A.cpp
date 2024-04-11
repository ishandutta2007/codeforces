//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
void solve(){
    int a,b,c,d,x,y,x1,y1,x2,y2;cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
    if (x+b-a>x2 || x+b-a<x1 || y+d-c>y2 || y+d-c<y1){
        cout<<"No\n";
        return;
    }
    if (a+b>0 && x1==x2){
        cout<<"No\n";
        return;
    }
    if (c+d>0 && y1==y2){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
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
/*
2
4
2 -2
2 2
-2 2
-2 -2
1
0 2 10
4
1 -1
1 1
-1 1
-1 -1
2
0 1 10
1 1 10
*/