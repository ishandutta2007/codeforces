#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=1e9+7;
#define N 300000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
main(){
    ll int n,x,y;
    cin>>n>>x>>y;
    char pre='1';
    ll int m=0;
    rep(i,n){
        char c;
        cin>>c;
        if(!(c==pre)){
            if(pre=='1') {m++; }
            pre=c; 
        }
    }
    if(m==0){
        cout<<0; return 0;
    }
    if(m==1){
        cout<<y; return 0;
    }
    cout<<min(y*m,x*(m-1)+y);
    return 0;
}