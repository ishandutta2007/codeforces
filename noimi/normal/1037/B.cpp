#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 310000
using namespace std;

main(){
    int n,s;
    cin>>n>>s;
    int a[N];
    rep(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    ll sum=0;
    rep(i,n)sum+=a[i];
    int mid=(n-1)/2;
    if(a[mid]==s){cout<<0;return 0;}
    if(a[mid]<s){
        ll ss=0;
        rep(i,mid){
            ss+=a[i];
        }
        rep2(i,mid,n-1){
            ss+=max(s,a[i]);
        }
        cout<<ss-sum;return 0;
    }
    else{
        ll ss=0;
        rep(i,mid+1){
            ss+=min(a[i],s);
        }
        rep2(i,mid+1,n-1)ss+=a[i];
        cout<<sum-ss;return 0;
    }
    return 0;
}