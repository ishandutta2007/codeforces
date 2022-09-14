//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    int x=min(n/k,m);
    m-=x;
    int y=(m+k-2)/(k-1);
    cout<<max(0,x-y)<<endl;
}
int main()
{
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
4
0100
1110
0101
0111
*/