#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
const long long mod=1000000007;
const int N=100010;
int a[2][N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;cin>>n>>q;
    int cnt=0;
    for (int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        x--;
        cnt-=(a[x^1][y]&a[x][y])+(a[x^1][y-1]&a[x][y])+(a[x^1][y+1]&a[x][y]);
        a[x][y]^=1;
        cnt+=(a[x^1][y]&a[x][y])+(a[x^1][y-1]&a[x][y])+(a[x^1][y+1]&a[x][y]);
        if (!cnt) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;

}