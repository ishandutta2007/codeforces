#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int ll
const int N=300010;
int l[N];
int r[N];
int mx[N];
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],mx[i]=l[i]=r[i]=0;
    for (int i=1;i<=n;i++){
        l[i]=0;
        for (int j=i-1;j>=1;j=l[j]){
            if (a[j]<a[i]){
                l[i]=j;
                break;
            }
        }
    }
    for (int i=n;i>=1;i--){
        r[i]=n+1;
        for (int j=i+1;j<=n;j=r[j]){
            if (a[j]<a[i]){
                r[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        mx[a[i]]=max(mx[a[i]],r[i]-l[i]-1);
    }
    for (int i=2;i<=n;i++) mx[i]=min(mx[i],mx[i-1]);
    for (int k=1;k<=n;k++){
        cout<<(k<=mx[n-k+1]);
    }
    cout<<endl;
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