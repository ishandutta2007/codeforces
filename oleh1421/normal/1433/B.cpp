#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
void solve(){
    int n;cin>>n;
    int l=-1,r=-1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]){
            if (l==-1) l=i;
            r=i;
        }
    }
    int res=0;
    for (int i=l;i<=r;i++) res+=(a[i]==0);
    cout<<res<<endl;
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