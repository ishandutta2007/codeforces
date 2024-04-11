#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[0]=1000000001;
    a[n+1]=1000000001;
    int ind=-1;
    for (int i=1;i<=n;i++){
        if ((a[i]>a[i-1] || a[i]>a[i+1]) && (ind==-1 || a[i]>a[ind])) ind=i;
    }
    cout<<ind<<endl;
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