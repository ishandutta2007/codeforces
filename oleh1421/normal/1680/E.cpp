//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=200010;
const ll inf=2e18;
const ll mod=1000000007;
int a[2][N];
void solve(int Case){
    int n;cin>>n;
    for (int it=0;it<2;it++){
        for (int i=1;i<=n;i++){
            char c;cin>>c;
            a[it][i]=(c=='*');
        }
    }
    int last=0;
    int mask=0;
    int res=0;
    for (int i=1;i<=n;i++){
        if (a[0][i]==0 && a[1][i]==0) continue;
        int cur=a[0][i]+a[1][i]*2;
        res+=a[0][i]+a[1][i];
        if (mask){
            res+=i-last-1;
            if ((mask&cur)==0){
                res++;
                cur=3;
            }
        }
        last=i;
        mask=cur;
    }
    cout<<res-1<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
1
4 5
1 2
2 3
3 4
1 3
2 4
**/