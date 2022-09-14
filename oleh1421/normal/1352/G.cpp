#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000007ll;

void solve(){
    int n;cin>>n;
    if (n<=3){
        cout<<-1<<endl;
        return;
    }
    if (n==4){
        cout<<"3 1 4 2\n";
        return;
    }
    if (n%2){
        for (int i=1;i<=n;i+=2) cout<<i<<" ";
        cout<<n-3<<" ";
        cout<<n-1<<" ";
        for (int i=n-5;i>=1;i-=2) cout<<i<<" ";
        cout<<endl;
    } else {
        for (int i=1;i<=n;i+=2) cout<<i<<" ";
        cout<<n-4<<" ";
        cout<<n<<" ";
        cout<<n-2<<" ";
        for (int i=n-6;i>=1;i-=2) cout<<i<<" ";
        cout<<endl;
    }

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