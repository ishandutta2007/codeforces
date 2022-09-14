#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;
const ll mod=1000000007;
int a[N];
int get(int x){
    int d=2;
    int res=0;
    while (d*d<=x){
        if (x%d==0){
            res++;
            x/=d;
        } else {
            d++;
        }
    }
    res+=(x>1);
    return res;
}
void solve(){
    int a,b,k;cin>>a>>b>>k;
    int g=__gcd(a,b);
    int x=get(a/g);
    int y=get(b/g);
    int z=get(g);
    if (x>y) swap(x,y);
    if (y==0){
        if (k==0 || (k>=2 && k<=2*z)){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
        return;
    }
    if (x==0){
        if ((k>=1 && k<=y+z*2)){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
        return;
    }
    if (k>=2 && k<=x+y+2*z){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
//
//    1...x
//    1...y
//    0 2...z



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