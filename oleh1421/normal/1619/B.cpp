#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const int N=1000100;
const ll mod=998244353;
void solve(){
    int n;cin>>n;
    int x=1;
    while (x*x<=n) x++;
    int y=1;
    while (y*y*y<=n) y++;
    int z=1;
    while (z*z*z*z*z*z<=n) z++;
    x--;
    y--;
    z--;
    cout<<x+y-z<<'\n';
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
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M