#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=200010;
const int L=20;
const ll mod=998244353;

void solve(){
    int n;cin>>n;
    map<int,int>mp;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    int mx=0;
    for (auto cur:mp) mx=max(mx,cur.second);
    ll res=0ll;
    while (mx<n){
        res++;
        res-=mx;
        mx=min(mx*2,n);
        res+=mx;
    }
    cout<<res<<endl;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
608
7 11 12 13 14 15 17 19


4
5 100
1 10
10 1
100 100
**/