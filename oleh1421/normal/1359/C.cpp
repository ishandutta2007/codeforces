//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
int a[N][N];
int n,m,x,y;
int f(int len){
    return (len/2)*y+(len%2)*x;
}
bool cmp(pair<ll,ll>a,pair<ll,ll>b){
    return (a.first*b.second<=a.second*b.first);
}
void solve(){
    ll h,c,t;cin>>h>>c>>t;
    h*=2;
    c*=2;
    t*=2;
    ll m=(h+c)/2;
    if (m>=t){
        cout<<2<<endl;
        return;
    }
    ll x=(h-t)/(t+t-m-m);
    x*=2;
    pair<ll,ll>r1={abs(x*m+h-t*x-t),x+1};
    x+=2;
    pair<ll,ll>r2={abs(x*m+h-t*x-t),x+1};
    x-=2;
    if (cmp(r1,r2)) cout<<x+1<<endl;
    else cout<<x+3<<endl;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4
0100
1110
0101
0111
*/