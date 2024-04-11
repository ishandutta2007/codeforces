
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int a[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int len=n-4;
    for (int l=0,r=len-1;r<n;l++,r++){
        string t=s.substr(0,l)+s.substr(r+1,n-r-1);
        if (t=="2020"){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";

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
//3 1 5 4 2 2
//3 1 1