#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000;
const int N=300010;
int a[N];
int dp[N];
void solve(){
    int n,s;cin>>n>>s;

    if (s<n+n){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<n;i++) cout<<2<<" ";
    cout<<s-(n-1)*2<<endl;
    cout<<1<<endl;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}