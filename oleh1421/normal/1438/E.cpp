#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300100;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    for (int r=1;r<=n;r++){
        int sum=0;
        for (int i=r-1;i>=2;i--){
            sum+=a[i];
            if (sum>=a[r]*2) break;
            if (a[i-1]<a[r] && sum==(a[r]^a[i-1])){
                res++;
            }
        }
    }
    reverse(a+1,a+n+1);
    for (int r=1;r<=n;r++){
        int sum=0;
        for (int i=r-1;i>=2;i--){
            sum+=a[i];
            if (sum>=a[r]*2) break;
            if (a[i-1]<a[r] && sum==(a[r]^a[i-1])){
                res++;
            }
        }
    }
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}