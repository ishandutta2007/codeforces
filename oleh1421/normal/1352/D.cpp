#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000007ll;
const int N=200010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=1;
    int r=n;
    int cnt=0;
    ll last=0ll;
    ll sum=0ll;
    ll A=0ll;
    ll B=0ll;
    while (l<=r){
        if (cnt%2==0){
            A+=a[l];
            sum+=a[l++];
            if (sum>last){
                last=sum;
                sum=0;
                cnt++;
            }
        } else {
            B+=a[r];
            sum+=a[r--];
            if (sum>last){
                last=sum;
                sum=0;
                cnt++;
            }
        }
    }
    if (sum) cnt++;
    cout<<cnt<<" "<<A<<" "<<B<<endl;

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