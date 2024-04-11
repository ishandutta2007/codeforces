//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=400010;
int ans[N];
int a[N],t[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        ans[i]=2e9;
    }
    for (int i=1;i<=k;i++){
        cin>>a[i];
    }
    for (int i=1;i<=k;i++){
        cin>>t[i];
        ans[a[i]]=t[i];
    }
    for (int i=1;i<n;i++){
        ans[i+1]=min(ans[i+1],ans[i]+1);
    }
    for (int i=n;i>=2;i--){
        ans[i-1]=min(ans[i-1],ans[i]+1);
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;



}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4 4
1 2
2 3
1 4
4 3
**/