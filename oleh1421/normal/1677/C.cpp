#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1000100;
const ll mod=1000000007;
int a[N],b[N];
int c[N];
int p[N];
bool used[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) c[a[i]]=b[i];
    for (int i=1;i<=n;i++) used[i]=false;
    int take=0;
    for (int i=1;i<=n;i++){
        int x=i;
        int len=0;
        while (!used[x]){
            used[x]=true;
            x=c[x];
            len++;
        }
        take+=len/2;

    }
    ll res=0ll;
    for (int i=1;i<=take;i++) res-=2*i;
    for (int i=1;i<=take;i++) res+=2*(n-i+1);
    cout<<res<<endl;


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/