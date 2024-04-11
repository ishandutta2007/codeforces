//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=300010;
ll a[N];
ll b[N];
ll c[N];
ll f(int i,int j,int t){
    return (a[i]-b[j])*(a[i]-b[j])+(b[j]-c[t])*(b[j]-c[t])+(c[t]-a[i])*(c[t]-a[i]);
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=1;i<=k;i++) cin>>c[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    sort(c+1,c+k+1);
    ll res=4000000000000000001ll;
    for (int i=1;i<=n;i++){
        int pos1=upper_bound(b+1,b+m+1,a[i])-b-1;
        int pos2=lower_bound(c+1,c+k+1,a[i])-c;
        if (pos1>0 && pos2<=k){
            res=min(res,f(i,pos1,pos2));
        }
        int pos3=lower_bound(b+1,b+m+1,a[i])-b;
        int pos4=upper_bound(c+1,c+k+1,a[i])-c-1;
        if (pos3<=m && pos4>0){
            res=min(res,f(i,pos3,pos4));
        }
    }
    for (int i=1;i<=m;i++){
        int pos1=upper_bound(a+1,a+n+1,b[i])-a-1;
        int pos2=lower_bound(c+1,c+k+1,b[i])-c;
        if (pos1>0 && pos2<=k){
            res=min(res,f(pos1,i,pos2));
        }
        int pos3=lower_bound(a+1,a+n+1,b[i])-a;
        int pos4=upper_bound(c+1,c+k+1,b[i])-c-1;
        if (pos3<=n && pos4>0){
            res=min(res,f(pos3,i,pos4));
        }
    }
    for (int i=1;i<=k;i++){
        int pos1=upper_bound(a+1,a+n+1,c[i])-a-1;
        int pos2=lower_bound(b+1,b+m+1,c[i])-b;
        if (pos1>0 && pos2<=m){
            res=min(res,f(pos1,pos2,i));
        }
        int pos3=lower_bound(a+1,a+n+1,c[i])-a;
        int pos4=upper_bound(b+1,b+m+1,c[i])-b-1;
        if (pos3<=n && pos4>0){
            res=min(res,f(pos3,pos4,i));
        }
    }
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/*
2 2
0 1
10 1
*/