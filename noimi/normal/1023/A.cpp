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
#define N 200000
using namespace std;
main(){
    string s,t;
    int n,m;
    cin>>n>>m;
    cin>>s>>t;
    int p=-1;
    rep(i,n){
        if(s[i]=='*') p=i;
    }
    if(p==-1){
        if(n!=m) {cout<<"NO"; return 0;}
        rep(i,n){
            if(s[i]!=t[i]){cout<<"NO";return 0;}
        }
        cout<<"YES";return 0;
    }
    rep(i,p){
        if(s[i]!=t[i]){cout<<"NO";return 0;}
    }
    rep(i,n-p-1){
        if(s[n-1-i]!=t[m-1-i]){cout<<"NO";return 0;}
    }
    if(n-1>m)cout<<"NO";else cout<<"YES";
    return 0;
}