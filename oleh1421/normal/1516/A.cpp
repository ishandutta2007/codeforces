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
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int k1=k;
    for (int i=1;i<=n;i++){
        if (a[i]>k){
            a[i]-=k;
            k=0;
        } else{
            k-=a[i];
            a[i]=0;
        }
    }
    a[n]+=k1-k;
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

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