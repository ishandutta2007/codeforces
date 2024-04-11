#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
void solve(){
    ll a,b,x,y,n;cin>>a>>b>>x>>y>>n;
    if (a+b-x-y<=n){
        cout<<x*y<<endl;
        return;
    }
    ll res=a*b;
    if (x+n>=a){
        res=min(res,x*(b-n+(a-x)));
    } else {
        res=min(res,(a-n)*b);
    }
    if (y+n>=b){
        res=min(res,y*(a-n+(b-y)));
    } else {
        res=min(res,a*(b-n));
    }
    cout<<res<<endl;
}
int main()
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
7
10 10 8 5 3
*/