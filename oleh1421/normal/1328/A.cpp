//#pragma GCC opitmize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
void solve(){
    int a,b;cin>>a>>b;
    cout<<(b-a%b)%b<<endl;
}
int32_t main()
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
10 100
1 99
1 3
1 3
1 3
1 3
1 3
1 3
1 3
1 3
1 3
*/