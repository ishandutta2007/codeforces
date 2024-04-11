//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
int a[N];

void solve(){
    int a,b,n;cin>>a>>b>>n;
    if (a>b) swap(a,b);
    int cnt=0;
    while (b<=n){
        a+=b;
        swap(a,b);
        cnt++;
    }
    cout<<cnt<<endl;

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
1
4
0 3 3 1
*/