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
    int n,m;cin>>n>>m;
    if (m<n){
        cout<<"No\n";
        return;
    }
    if (n%2){
        cout<<"Yes\n";
        for (int i=1;i<n;i++) cout<<1<<" ";
        cout<<m-n+1<<'\n';
        return;
    }
    if (m%2){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    for (int i=1;i<=n-2;i++) cout<<1<<" ";
    cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<'\n';

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