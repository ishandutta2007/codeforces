#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int ans[N];
void solve(){
    int n;cin>>n;
    int d=0;
    for (int i=0;i<=30;i++){
        ans[i]=(1<<i);
    }
    int sum=0;
    for (int i=0;i<=30;i++){
        sum+=ans[i];
        if (sum>=n){
            d=i;
            break;
        }
    }
    int extra=sum-n;
    for (int i=d;i>=1;i--){
        ll need=(ans[i]-ans[i-1]+0ll)*(d-i+1ll);
        if (extra>need){
            extra-=need;
            for (int j=d;j>=i;j--) ans[j]=ans[i-1];
            //cout<<i<<" "<<extra<<" "<<ans[3]<<endl;
        } else {
            int dv=(extra/(d-i+1));
            int c=(extra%(d-i+1));
            for (int j=d;j>=i;j--) ans[j]-=dv;
            for (int j=i;j<i+c;j++) ans[j]--;
            break;
        }
    }
    cout<<d<<endl;
    for (int i=1;i<=d;i++) cout<<ans[i]-ans[i-1]<<" ";
    cout<<endl;


}
int32_t main()
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
/*
2 3
1 100
*/