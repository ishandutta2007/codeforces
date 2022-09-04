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
#define MAX_V 900010
using namespace std;
main(){
    int n,m;
    cin>>n>>m;
    int a[N];
    int M=0;
    rep(i,n)cin>>a[i];
    rep(i,n) M=max(M,a[i]);
    int s=m;
    rep(i,n){
        m-=(M-a[i]);
    }
    if(m<=0){
        cout<<M<<" ";
    }
    else{
        cout<<M+(m+n-1)/n<<" ";
    }
    cout<<M+s;
    return 0;
}