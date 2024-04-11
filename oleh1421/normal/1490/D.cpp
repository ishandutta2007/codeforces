//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
int d[N],p[N];
void rec(int l,int r,int depth){
    if (l>r) return;
    int mx=0;
    for (int i=l;i<=r;i++){
        if (p[i]>p[mx]) mx=i;
    }
    d[mx]=depth;
    rec(l,mx-1,depth+1);
    rec(mx+1,r,depth+1);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    rec(1,n,0);
    for (int i=1;i<=n;i++) cout<<d[i]<<" ";
    cout<<endl;

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
1
3 3
1 -3 4
1 5 2
*/