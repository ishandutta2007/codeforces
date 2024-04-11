//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
//#define prev aboba
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=600010;
const ll mod=998244353;
const ll inf=1e18;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=a[n]-a[1];
    for (int i=1;i<n;i++) res=max(res,a[n]-a[i]);
    for (int i=2;i<=n;i++) res=max(res,a[i]-a[1]);
    for (int i=1;i<n;i++) res=max(res,a[i]-a[i+1]);
    cout<<res<<'\n';



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
9
1 2 1
1 3 1
1 4 1
1 5 1
2 6 1
3 7 1
4 8 1
5 9 1
*/