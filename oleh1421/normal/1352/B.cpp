#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000007ll;
const int N=510;
void solve(){
    int n,k;cin>>n>>k;
    if (n<k){
        cout<<"NO\n";
        return;
    }
    if (k%2==n%2){
        cout<<"YES\n";
        for (int i=1;i<k;i++) cout<<1<<" ";
        cout<<n-k+1<<endl;
        return;
    }
    if (n%2){
        cout<<"NO\n";
        return;
    }
    n/=2;
    if (n<k){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<k;i++) cout<<1*2<<" ";
    cout<<(n-k+1)*2<<endl;
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