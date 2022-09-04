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

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
main(){
    int n,k;
    cin>>n>>k;
    int a[N];
    int g=k;
    rep(i,n){
        cin>>a[i];
        a[i]%=k;
        g=gcd(g,a[i]);
    }
    int flag[N];
    int t=0,count=0;
    while(1){
        if(flag[t]) break;
        flag[t]=1;
        t=(t+g)%k;
        count++;
    }
    cout<<count<<endl;
    rep(i,k){
        if(flag[i]){
            cout<<i<<" ";
        }
    }
    return 0;

}