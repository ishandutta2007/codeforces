//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=5000100;
const ll mod=1000000007;
ll a[N];
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (ll b=sqrt(a[1]);b<=sqrt(a[1]);b++){
        if (b*b+b<a[1]) continue;
        ll L=max(0ll,b*b-a[1]);
        ll R=b*b+b-a[1];

        for (int i=2;i<=n;i++){
            ll cur=a[i]+L;
            ll b1=sqrt(cur);
            if (b1*b1+b1>=cur) R=min(R,L+b1*b1+b1-cur);
            else L=max(L,L+(b1+1)*(b1+1)-cur);
        }
        if (L<=R){
            cout<<L<<endl;
            return;
        }
    }
    for (ll b=sqrt(a[1])+1;b<N;b++){
        ll add=b*b-a[1];
        ll L=0;
        ll R=b;
        int pos=2;
        for (ll b1=b;;b1++){
            int nxt=lower_bound(a+1,a+n+1,(b1+1)*(b1+1)-add)-a;
            int mid=upper_bound(a+1,a+n+1,b1*b1+b1-add)-a-1;
            if (pos<=mid && mid<nxt){
                R=min(R,b1*b1+b1-a[mid]-add);
            }
            mid++;
            if (pos<=mid && mid<nxt){
                L=max(L,(b1+1)*(b1+1)-a[mid]-add);
            }
            if (nxt==n+1 || L>R) break;
            pos=nxt;
        }
        if (L<=R){
            cout<<add+L<<endl;
            return;
        }
    }


}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
//    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
3
1 -1 1
**/