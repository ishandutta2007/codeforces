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
    ll int n;
    cin>>n;
    ll int ans=0;
    vector<int> v={1,2,3,4,5,6,6,6,6,4,3,2,1};
    rep(i,13){
        if(n>i-1){
            ans+=(n+1-i)*v[i];
        }
    }
    cout<<ans;
    return 0;
}