//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=1010;
int ask(int ind){
    cout<<"? "<<ind<<endl;
    int ans;cin>>ans;
    return ans;
}
void solve(){
    int n;cin>>n;
    int L=1,R=n;
    while (R>L){
        int mid=(L+R)/2;
        int x=ask(mid);
        int y=ask(mid+1);
        if (x<y) R=mid;
        else L=mid+1;
    }
    cout<<"! "<<L<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
3
a
a
b
*/