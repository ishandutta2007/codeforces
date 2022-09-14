//#pragma GCC opitmize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
int c[N];
void ans(int n,int i,int j){
    for (int t=1;t<=n;t++){
        if (t==i || t==j) cout<<"b";
        else cout<<"a";
    }
    cout<<endl;
}
void solve(){
    ll n,k;cin>>n>>k;
    k=n*(n-1ll)/2ll-k+1ll;
    for (int i=1;i<=n;i++){
        if (k<=n-i){
            ans(n,i,i+k);
            return;
        }
        k-=n-i;
    }
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
10 7
1 1 1 3 3 3 35 40 40 40
*/