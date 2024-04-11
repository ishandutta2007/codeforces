#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
#define vec vector<int>
using namespace std;

void print(ll x){
    printf("%lld",&x);return;
}

main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int e=0;
    rep(i,s.size()){
        if(s[i]=='8')e++;
    }
    cout<<min(e,n/11);
    return 0;
}