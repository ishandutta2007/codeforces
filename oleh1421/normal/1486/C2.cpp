//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=200010;
const ll mod=1000000007ll;
const int A=1000100;
map<pair<int,int>,int>mp;
int get(int l,int r){
    if (l==r) return -1;
    if (mp.find({l,r})!=mp.end()) return mp[{l,r}];
    cout<<"? "<<l<<" "<<r<<endl;
    int ans;cin>>ans;
    return mp[{l,r}]=ans;
}
void solve(){
    int n;cin>>n;
    int x=get(1,n);
    if (get(1,x)==x){
        int res=x;
        for (int i=20;i>=0;i--){
            if (res-(1<<i)<=0) continue;
            if (get(res-(1<<i),x)!=x) res-=(1<<i);
        }
        cout<<"! "<<res-1<<endl;
    } else {
        int res=x;
        for (int i=20;i>=0;i--){
            if (res+(1<<i)>n) continue;
            if (get(x,res+(1<<i))!=x) res+=(1<<i);
        }
        res++;
        cout<<"! "<<res<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}