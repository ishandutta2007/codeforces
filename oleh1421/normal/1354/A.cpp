#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000;
const int N=300010;
ll h[N];
void solve(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    if (a<=b){
        cout<<b<<endl;
        return;
    }
    if (c<=d){
        cout<<"-1\n";
        return;
    }
    a-=b;
    cout<<((a+c-d-1)/(c-d))*c+b<<endl;


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