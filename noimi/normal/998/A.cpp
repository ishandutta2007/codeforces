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
    int n;
    cin>>n;
    int a[N];
    int sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(n==1||(n==2&&a[0]==a[1])){
        cout<<-1; return 0;
    }
    rep(i,n){
        if(a[i]*2!=sum){
            cout<<1<<endl<<i+1;
            return 0;
        }
    }
    return 0;
}