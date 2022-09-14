#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N],b[N],m[N];
map<int,vector<int> >mp;
ll x[N];
int leave[N];
void solve(){
    mp.clear();
    int n;cin>>n>>m[1];
    ll sum=0ll;
    for (int i=2;i<=n;i++) m[i]=m[i-1];

    for (int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        sum+=a[i]+b[i]-m[i];
        int cur=max(0,a[i]-m[i]);
        sum-=cur*2;
        a[i]-=cur;
    }
    for (int i=1;i<=n;i++){
        x[i]=min(a[i],a[i]+b[i]-m[i]);
    }
//    cout<<sum<<endl;
    ll cur=0ll;
    for (int i=1;i<=n;i++){
        leave[i]=max(0ll,min(x[i],sum/2-cur));
        cur+=leave[i];
    }
    cout<<abs(sum-cur*2ll)<<endl;
    for (int i=1;i<=n;i++){
        cout<<a[i]-leave[i]<<" "<<m[i]-a[i]+leave[i]<<endl;
    }


}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
2 2
1 3
4 2
**/