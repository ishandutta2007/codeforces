#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=503000;
const ll mod=998244353;

void solve(){
    string s;cin>>s;
    s+="1";
    int res=0;
    for (int i=1;i<s.size();i++){
        if (s[i]=='1' && s[i-1]=='0') res++;
    }
    cout<<min(res,2)<<endl;
}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}