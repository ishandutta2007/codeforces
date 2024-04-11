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
    int n,b,a[200];
    cin>>n>>b;
    rep(i,n){
        cin>>a[i];
    }
    vector<int> v;
    int e=0;
    rep(i,n-1){
        if(a[i]%2){
            e++;
        }
        if(e*2==i+1){
            v.push_back(abs(a[i+1]-a[i]));
        }
    }
    int ans=0;
    int pos=0;
    if(v.empty()) {cout<<0; return 0;}
    sort(v.begin(),v.end());
    while(b-v[pos]>=0){
        b-=v[pos];
        ans++;
        pos++;
        if(pos==v.size()) break;
    }
    cout<<ans;
    return 0;
}