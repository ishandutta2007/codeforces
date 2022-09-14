//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
int a[N];
int cnt[N];
void solve(){
    int n,p,k;cin>>n>>p>>k;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
    }
    int x,y;cin>>x>>y;
    for (int i=0;i<=k;i++) cnt[i]=0;
    int res=x*n;
    for (int i=n;i>=p;i--){
        if (a[i]==0) cnt[i%k]++;
        res=min(res,cnt[i%k]*x+y*(i-p));
    }
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