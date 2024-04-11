#pragma GCC optimize ("Ofast")
/// #pragma GCC target("avx2")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
using namespace std;
int w(int x1,int y1,int x2,int y2){
     if ((x2-x1+1)%2 && (y2-y1+1)%2){
        if ((x1+y1)%2) return ((x2-x1+1)*(y2-y1+1)/2);
        else return ((x2-x1+1)*(y2-y1+1)/2+1);
     } else return ((x2-x1+1)*(y2-y1+1)/2);
}
int b(int x1,int y1,int x2,int y2){
     return (x2-x1+1)*(y2-y1+1)-w(x1,y1,x2,y2);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        int x1,y1,x2,y2,x3,y3,x4,y4;cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        int res=w(1,1,n,m);
        int x5=max(x1,x3);
        int y5=max(y1,y3);
        int x6=min(x2,x4);
        int y6=min(y2,y4);
        res+=b(x1,y1,x2,y2);
        res-=w(x3,y3,x4,y4);
        if (x5<=x6 && y5<=y6) res-=b(x5,y5,x6,y6);
        cout<<res<<" "<<n*m-res<<endl;
    }
    return 0;
}