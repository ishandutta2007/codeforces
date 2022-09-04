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
    int n;
    cin>>n;
    int a[N];
    rep(i,n){
        cin>>a[i];
    }
    int num1=0;
    int used1[N]={};
    ll int ans=0;
    rep(i,n){
        if(!used1[a[i]]){
            used1[a[i]]=1; num1++;
        }
        else used1[a[i]]++;
    }
    int used[N]={},num=0;
    rep(i,n){
        used1[a[i]]--;
        if(used1[a[i]]==0) num1--;
        if(!used[a[i]]){
            used[a[i]]=1;
            ans+=num1;
        }
        
    }
    cout<<ans;
    return 0;
}