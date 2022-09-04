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
#define N 610000
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll n,q;cin>>n>>q;
    rep(i,q){
        ll a,b;
        cin>>a>>b;
        if((a+b)%2){
            if(n%2){
                if(a%2)
                cout<<(n*n+1)/2+((a-1)/2*n)+(b+1)/2;
                else
                cout<<(n*n+1)/2+((a-1)/2*n)+(b+1)/2+n/2;
            }
            else{
                cout<<n*n/2+(a-1)*n/2+(b+1)/2;
            }
        }
        else{
            if(n%2){
                if(a%2)
                cout<<((a-1)/2*n)+(b+1)/2;
                else
                cout<<((a-1)/2*n)+(b+1)/2+(n+1)/2;
            }
            else{
                cout<<(a-1)*n/2+(b+1)/2;
            }
        }
        cout<<endl;
    }
    return 0;
}