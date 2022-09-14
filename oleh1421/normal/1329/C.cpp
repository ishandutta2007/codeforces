//#pragma GCC opitmize ("trapv")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=(1<<22)+100;
int a[N];
int cnt[N];
int get(int i){
    if (a[i+i]+a[i+i+1]==0){
        return i;
    }
    if (a[i+i]>a[i+i+1]){
        return get(i+i);
    } else {
        return get(i+i+1);
    }
}
void f(int i){
    cnt[i]--;

    if (a[i+i]+a[i+i+1]==0){
        a[i]=0;
        return;
    }
    if (a[i+i]>a[i+i+1]){
        a[i]=a[i+i];
        f(i+i);
    } else {
        a[i]=a[i+i+1];
        f(i+i+1);
    }
}
int h,g;

vector<int>ans;
void go(int v){

    if (v>=(1<<g)) return;
//    if (a[v]>a[v^1]){
//        go(v/2);
//        return;
//    }
    if (get(v)>=(1<<g)){

        f(v);
        ans.push_back(v);
        go(v);
        return;
    }
    go(v+v);
    go(v+v+1);
}
void solve(){
    cin>>h>>g;
    a[0]=1000000001;
    for (int i=1;i<(1<<h);i++) cin>>a[i];
    cnt[1]=(1<<h)-1;
    for (int i=2;i<(1<<h);i++){
        cnt[i]=cnt[i/2]/2;
    }
    ans.clear();
    go(1);
    ll sum=0ll;
    for (int i=1;i<(1<<g);i++) {
        sum+=a[i];
    }
    cout<<sum<<endl;
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;
    for (int i=1;i<(1<<h);i++) a[i]=cnt[i]=0;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}