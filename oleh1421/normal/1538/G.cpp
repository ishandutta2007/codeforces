#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
#define int ll
const int N=300010;
const ll mod=1000000007;
ll dv(ll a,ll b){
    if (a<0) return 0;
    return a/b+1;
}
int R,B,a,b;
int f1(int x){
    return (R-x*(a-b))/b;
}
int f2(int x){
    return (B+x*(a-b))/a;
}
void solve(){
    cin>>R>>B>>a>>b;

    if (a<b){
        swap(a,b);
    }
    int d=a-b;
    int x=0;
    for (int i=29;i>=0;i--){
        if (x+(1<<i)<=min(R/a,B/b) && f1(x+(1<<i))>=f2(x+(1<<i))) x+=(1<<i);
    }
    ll res=0ll;
    res=max(res,min(f1(x),f2(x)));

    x++;
    res=max(res,min(f1(x),f2(x)));
    cout<<res<<endl;

}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}