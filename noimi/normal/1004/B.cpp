#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=998244353;
#define N 300000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n,m;
    cin>>n>>m;
    rep(i,n){
        if(i%2) cout<<1;
        else cout<<0;
    }
    return 0;
}