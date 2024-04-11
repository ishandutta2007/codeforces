#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(ll int i=(a);i<=(b);++i)
#define rep(i,n) for(ll int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define MOD 998244353
#define N 1100000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

ll int power(ll int a,ll int b){
    ll int t=a,ans=1;
    while(b){
        if(b%2) ans=(ans*t)%MOD;
        t=(t*t)%MOD;
        b=b/2;
    }
    return ans;
}
ll int inv[N];
void calc(){
    inv[1]=1;
    rep2(i,2,1010000){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
ll int comb[N];
void cal(ll int m){
    comb[0]=1;
    rep2(i,1,m){
        comb[i]=((comb[i-1]*(m+1-i)%MOD)*inv[i])%MOD;
    }
    return;
}
main(){
    ll int n;
    cin>>n;
    calc();
    cal(n);
    ll int s=power(power(3,n)-3,n);
    ll int sum=(power(3,n*n)-s+MOD)%MOD;
    ll int a=1;
    rep2(i,1,n){
        sum=(MOD+sum+a*(power(3,i)-3)*comb[i]%MOD*power(power(3,n-i),n)%MOD+a*3*(comb[i]*power(power(3,n-i)-1,n)%MOD)%MOD)%MOD;
        a*=-1;
    }
    cout<<(sum+MOD)%MOD;
    return 0;
}