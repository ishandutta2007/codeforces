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
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    double m,a[N],b[N];
    cin>>n>>m;
    double mm=m;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }
    vector<double> c;
    c.pb(a[0]);
    rep2(i,1,n-1){
        c.pb(b[i]);
        c.pb(a[i]);
    }
    c.pb(b[0]);
    for(int i=2*n-1;i>=0;i--){
        if(c[i]==1.0){
            cout<<-1; return 0;
        }
        m=m+m/(c[i]-1.0);
    }
    printf("%.10f",m-mm);
    return 0;
}