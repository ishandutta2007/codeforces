#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'
const int N=100100;
const ll mod=998244353;
int a[N];
int x[N],y[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1){
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<-a[1]<<endl;
        return;
    }
    x[1]=0;
    y[1]=-a[1];
    for (int i=2;i<=n;i++){
//        n*x+(n-1)*y==a[i]
        x[i]=((n-1-a[i])%(n-1)+n-1)%(n-1);
        y[i]=(-x[i]-a[i])/(n-1)-x[i];
    }
    cout<<1<<" "<<n<<endl;
    for (int i=1;i<=n;i++) cout<<x[i]*n<<" ";
    cout<<endl;
    cout<<1<<" "<<1<<endl;
    cout<<y[1]<<endl;
    cout<<2<<" "<<n<<endl;
    for (int i=2;i<=n;i++) cout<<y[i]*(n-1)<<" ";
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
//1 3 3 4
//0 1 2 3