#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 5e5+5;
int a[maxn], n;
ll b[maxn];
ll check(int p){
    memset(b,0,sizeof b);
    ll ans = 0;
    fors(i,p+1,n+1){
        ll t = (b[i-1]+1+a[i]-1)/a[i];
        ans += t; b[i] = t*a[i];
    }
    for(int i = p-1; i > 0; --i){
        ll t = (b[i+1]+a[i])/a[i];
        ans += t; b[i] = t*a[i];
    }return ans;
}
int main(){
    cin>>n;
    fors(i,1,n+1) cin>>a[i];
    ll ans = 1e18;
    fors(i,1,n+1){
        ans = min(ans, check(i));
    }
    cout<<ans<<endl;
    return 0;
}