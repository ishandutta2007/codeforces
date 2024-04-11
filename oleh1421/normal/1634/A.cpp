#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=5000010;
const ll mod=998244353;

void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    string s1=s;
    reverse(s.begin(),s.end());
    if (s1==s || k==0){
        cout<<1<<endl;
    } else {
        cout<<2<<endl;
    }


}
int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**

**/