#include <bits/stdc++.h>
#define endl '\n'
#define inf 1000000000000000001ll
#define lcm my_lcm
#define gcd my_gcd
typedef long long ll;
using namespace std;
void solve(){
    ll a,b,k;cin>>a>>b>>k;
    int g=__gcd(a,b);
    a/=g;
    b/=g;
    if (a>b) swap(a,b);
    if (b==1) cout<<"OBEY\n";
    else if (((b-2)/a)+1>=k) cout<<"REBEL\n";
    else cout<<"OBEY\n";

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
1
5 12
1 1
2 2
3 3
4 4
5 5

5 3
1 5
3 4

4 1
2 3
3 1
1 2
*/