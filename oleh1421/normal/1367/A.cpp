//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
void solve(){
    string b;cin>>b;
    string a="";
    a+=b[0];
    for (int i=1;i<b.size();i+=2){
        a+=b[i];
    }
    cout<<a<<endl;
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