#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=100010;
ld dist(ll a,ll b){
    return sqrtl(a*a+b*b);
}
void solve(){
    ll W,H;cin>>W>>H;
    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    ll w,h;cin>>w>>h;
    if (w+x2-x1>W && h+y2-y1>H){
        cout<<-1<<endl;
        return;
    }
    ll res=inf;
    if (w+x2-x1<=W){
        res=min(res,max(x2-(W-w),0ll));
        res=min(res,max(w-x1,0ll));
    }
    if (h+y2-y1<=H){
        res=min(res,max(y2-(H-h),0ll));
        res=min(res,max(h-y1,0ll));
    }
    cout<<res<<endl;



}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 5
2 1 7 4
4 2
**/