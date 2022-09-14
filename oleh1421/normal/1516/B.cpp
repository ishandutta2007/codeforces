#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=500010;
const ll mod=1000000007;
int a[N];
void solve(){
    int n;cin>>n;
    int Xr=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        Xr^=x;
        a[i]=x;
    }
    if (Xr==0) {
        cout<<"YES\n";
        return;
    }
    int cur=0;
    int cnt=0;
    for (int i=1;i<=n;i++){
        cur^=a[i];
        if (cur==Xr){
            cnt++;
            cur=0;
        }
    }
    if (cnt>=3) cout<<"YES\n";
    else cout<<"NO\n";

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