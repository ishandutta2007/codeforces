#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=1000010;
const ll mod=1000000007;

void solve(){
    ll n;cin>>n;
    if (n%2050){
        cout<<-1<<endl;
        return;
    }
    n/=2050;
    int res=0;
    while (n){
        res+=n%10;
        n/=10ll;
    }
    cout<<res<<endl;
}
int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 9 7
...##....
..#.##..#
..#....##
.##...#..
....#....
W
**/

/**
3 2 3
3 3
2 2
1 1
**/