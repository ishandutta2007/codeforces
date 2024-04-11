#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
void solve(){
    int n,x,y;cin>>n>>x>>y;
    int mn=1000000001;
    for (int i=1;i<=n;i++) a[i]=-1;
    for (int i=1;i<n;i++){
        if ((y-x)%i) continue;
        int d=(y-x)/i;

        int p=min(n-i,(x-1)/d+1);
        int cur=x+(n-p)*d;
        if (cur<mn){
            mn=cur;
            a[1]=x-(p-1)*d;
            for (int j=2;j<=n;j++) a[j]=a[j-1]+d;
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
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