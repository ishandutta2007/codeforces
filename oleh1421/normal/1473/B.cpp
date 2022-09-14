//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
int a[N];
void solve(){
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();
    int sz=n*m/__gcd(n,m);
    string s="";
    for (int i=1;i<=sz/n;i++) s+=a;
    string t="";
    for (int i=1;i<=sz/m;i++) t+=b;
    if (s==t) cout<<s<<endl;
    else cout<<"-1\n";
}
int32_t main()
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
/*


*/