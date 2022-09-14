//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=1000010;

void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=k-3;i++) cout<<1<<" ";
    n-=k-3;
    int x=1;
    while (n%2==0){
        x*=2;
        n/=2;
    }
    if (n==1){
        x/=4;
        cout<<x<<" "<<x<<" "<<2*x<<endl;
    } else{
        cout<<x<<" "<<x*(n/2)<<" "<<x*(n/2)<<endl;
    }


}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
4
3
1 1 2
2 2
1 2 10
2 1 10
1

10 3
2

**/