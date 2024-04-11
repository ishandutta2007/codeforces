//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=1000100;
const ll mod=998244353;
const ll inf=1000000000000000000;

void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++) cout<<"(";
        for (int j=0;j<i;j++) cout<<")";
        for (int j=0;j<n-i;j++) cout<<"(";
        for (int j=0;j<n-i;j++) cout<<")";
        cout<<endl;
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
//1 3 3 4
//0 1 2 3