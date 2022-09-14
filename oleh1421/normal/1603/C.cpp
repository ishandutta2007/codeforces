//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
const ll mod=998244353;
int a[N];
ll sum[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[0]=0;
    sum[0]=0;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        vector<int>can1,can2;
        for (int j=1;(j-1)*(j-1)<=a[i] && j<=a[i];j++) {
            can1.push_back(j);
            can2.push_back((a[i]+j-1)/j);
        }
        reverse(can2.begin(),can2.end());
        for (int j:can2) can1.push_back(j);
        for (int it=1;it<=3;it++){
            for (int j=1;j<can1.size();j++){
                if (can1[j]<can1[j-1]) swap(can1[j-1],can1[j]);
            }
        }
        vector<int>val;
        for (int j:can1){
            int z=a[i]/j;
            val.push_back((1ll*(j-1ll)*i+sum[(a[i-1]+z-1)/z])%mod);
        }
        for (int j=0;j<can1.size();j++) sum[can1[j]]=val[j];
        res+=sum[1];
        res%=mod;
//        for (int j:can1){
//            cout<<j<<" "<<sum[j]<<endl;
//        }
    }
    cout<<res<<endl;

//    n mod x = y mod n

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
8
6 7
3 2
8 3
5 7
7 4
7 1
7 3
1
1 0
**/