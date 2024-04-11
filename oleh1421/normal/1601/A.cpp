//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N];
int cnt[33];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        for (int j=0;j<30;j++){
            if (a[i]&(1<<j)) cnt[j]++;
        }
    }
    int g=0;
    for (int i=0;i<30;i++) g=__gcd(g,cnt[i]),cnt[i]=0;
    for (int k=1;k<=n;k++){
        if (g%k==0) cout<<k<<" ";
    }
    cout<<endl;

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5
1
1
2
1
0
2
4
0
1
4

**/