//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400010;
const ll mod=1000000007;
int a[N];
void solve(){
    string s;cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++){
        a[i+1]=s[i]-'a'+1;
    }
    if (n==1){
        cout<<0<<endl;
        return;
    }
    int res=0;
    if (a[1]==a[2]) a[2]=0,res++;
    for (int i=3;i<=n;i++){
        if (a[i]==a[i-1] || a[i]==a[i-2]) a[i]=0,res++;
    }
    cout<<res<<endl;
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


*/