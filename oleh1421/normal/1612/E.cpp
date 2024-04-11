//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=260000;
const ll mod=998244353;
int a[N],b[N];
ll A,B;
void upd_ans(ll x,ll y){
    if (A*y<B*x){
        A=x;
        B=y;
    }
}
vector<int>g[N];
void solve(){
    A=0,B=1;
    int n;cin>>n;
    int mx=0;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i],g[a[i]].push_back(i),mx=max(mx,b[i]);
//    vector<pair<ll,int> >v;
//    sort(v.begin(),v.end());
//    reverse(v.begin(),v.end());
    vector<int>A;
    for (int i=1;i<=200000;i++){
        if (!g[i].empty()) A.push_back(i);
    }
    for (int t=1;t<mx;t++){
        vector<pair<int,int> >v;
        for (int m:A){
            int sum=0;
            for (int i:g[m]){
                sum+=min(t,b[i]);
            }
            v.push_back({sum,m});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ll sum=0ll;
        for (int i=0;i<min(t,(int)v.size());i++) sum+=v[i].first;
        upd_ans(sum,t);
    }
    if (mx<=n){
        vector<pair<int,int> >v;
        for (int m:A){
            int sum=0;
            for (int i:g[m]){
                sum+=b[i];
            }
            v.push_back({sum,m});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ll sum=0ll;
        for (int i=0;i<v.size();i++){
            sum+=v[i].first;
            if (i+1>=mx) upd_ans(sum,i+1);
        }
    }
    int t=B;
    vector<pair<int,int> >v;
    for (int m:A){
        int sum=0;
        for (int i:g[m]){
            sum+=min(t,b[i]);
        }
        v.push_back({sum,m});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout<<t<<endl;
    for (int i=0;i<min(t,(int)v.size());i++) cout<<v[i].second<<" ";
    cout<<endl;


}
int32_t  main()
{
//    cin>>X>>Y;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/**
11 3
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
9 10
10 11
**/