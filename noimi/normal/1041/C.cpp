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
#define N 600010
using namespace std;
int n,m,d;
pii a[N];
bool check(int x){
    int b[N];
    rep(i,n){
        int s=i%x;
        if(i<x)b[i]=a[i].first;
        else if(a[i].first-b[s]<=d)return false;
        else b[s]=a[i].first;
    }
    return true;
}
main(){
    cin>>n>>m>>d;
    rep(i,n){
        cin>>a[i].first;a[i].second=i;
    }
    sort(a,a+n);
    int l=0,r=n;
    while(l+1<r){
        int mid=(l+r)/2;
        if(mid==0){
            r=1;break;
        }
        if(check(mid)){
            r=mid;
        }
        else l=mid;
    }
    cout<<r<<endl;
    int b[N];
    rep(i,n){
        b[a[i].second]=i%r+1;
    }
    rep(i,n){
        cout<<b[i]<<" ";
    }
    return 0;
}