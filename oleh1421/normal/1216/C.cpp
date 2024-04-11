#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int a[200001];
int x1,y1,x2,y2;
int x3,y3,x4,y4;
int x5,y5,x6,y6;
bool is_inside1(int x,int y){
    if ((x<x3 || x>x4 || y<y3 || y>y4)) return false;
    else return true;
}
bool is_inside2(int x,int y){
    if ((x<x5 || x>x6 || y<y5 || y>y6)) return false;
    else return true;
}
void solve(){
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;
    x3=max(x3,x1);
    y3=max(y3,y1);
    x4=min(x4,x2);
    y4=min(y4,y2);
    x5=max(x5,x1);
    y5=max(y5,y1);
    x6=min(x6,x2);
    y6=min(y6,y2);
    int x,y,xx,yy;
    x=max(x3,x5);
    y=max(y3,y5);
    xx=min(x4,x6);
    yy=min(y4,y6);
    int a=max(0ll,xx-x);
    int b=max(0ll,yy-y);
    int a1=max(0ll,x4-x3);
    int b1=max(0ll,y4-y3);
    int a2=max(0ll,x6-x5);
    int b2=max(0ll,y6-y5);
    if (a1*b1+a2*b2-a*b==(x2-x1)*(y2-y1)) cout<<"NO";
    else cout<<"YES";


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;tt=1;
    while (tt--){
        solve();
    }
    return 0;
}