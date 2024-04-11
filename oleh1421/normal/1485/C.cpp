//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int a[N];
void solve(){
    int x,y;cin>>x>>y;
//    1<=k<b
//    1<=b<=y
//    1<=k*(b+1)<=x
    ll res=0;
    int b=2;

    while (b<=y+1 && b-2<=x/b){
        res+=min(b-2,x/b);
        b++;
    }
//    cout<<res<<" ";
    for (;b<=y+1 && b<=x;b++){
        int nxt=min(x/(x/b),min(x,y+1));

        res+=(x/b)*(nxt-b+1ll);
        b=nxt;
    }

    cout<<res<<endl;
//    1<=k<=min(b-1,x/(b+1))

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
6 5 10
2 4 6 7 8 9
1 4
1 2
3 5
1 6
5 5

*/