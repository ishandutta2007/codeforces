//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=305010;
const ll mod=1000000007;

void solve(){
    int n;cin>>n;
    if (n==1){
        cout<<9<<endl;
        return;
    }
    cout<<98;
    for (int i=0;i<n-2;i++){
        cout<<(i+9)%10;
    }
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
5
2 2 2 2 2
*/