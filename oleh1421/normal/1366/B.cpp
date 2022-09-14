//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=5000001;
int l[N];
int r[N];
void solve(){
    int n,x,m;cin>>n>>x>>m;
    for (int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    int L=x;
    int R=x;
    for (int i=1;i<=m;i++){
        if (r[i]<L || l[i]>R) continue;
        R=max(R,r[i]);
        L=min(L,l[i]);
    }
    cout<<R-L+1<<endl;
}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
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
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/