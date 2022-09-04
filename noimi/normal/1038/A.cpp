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

main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a[26]={};
    rep(i,n){
        a[(int)(s[i]-'A')]++;
    }
    int ans=INF;
    rep(i,k){
        ans=min(ans,a[i]);
    }
    cout<<ans*k;
    return 0;
}