#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
int a[N];
void solve(){
    int n;cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if (sum==0){
        cout<<"NO\n";
    } else if (sum>0){
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;

    } else {
        sort(a+1,a+n+1);
//        reverse(a+1,a+n+1);
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}
///6 18 21
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}