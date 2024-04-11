#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000;
const int N=300010;
ll h[N];
int last[3];
const double PI=3.14159265358979323846264338327;
void solve(){
    int n;cin>>n;
    n+=n;
    double L=(PI)/(double)n;
    double R=0.5/tan(L);
    cout<<setprecision(10)<<fixed<<R*2.0<<endl;



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