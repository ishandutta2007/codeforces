
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
const ll mod=998244353;
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
ll f[N];
ll rf[N];
ll C(int n,int k){
    if (k<0 || k>n) return 0;
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}
vector<ll>mult(vector<ll>A,vector<ll>B){
    if (A.empty() || B.empty()) return {};
    vector<ll>C((int)A.size()+(int)B.size()-1);
    for (int i=0;i<A.size();i++){
        for (int j=0;j<B.size();j++){
            C[i+j]=(C[i+j]+A[i]*B[j])%mod;
        }
    }
    return C;
}
vector<ll>add(vector<ll>A,vector<ll>B){
    vector<ll>C(max(A.size(),B.size()),0);
    for (int i=0;i<A.size();i++) C[i]+=A[i];
    for (int i=0;i<B.size();i++) C[i]+=B[i];

    for (int i=0;i<C.size();i++){
        C[i]%=mod;
    }
    return C;
}
void print(vector<ll>v){
    for (auto i:v){
        if (i>mod/2) cout<<i-mod<<" ";
        else cout<<i<<" ";
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,l;cin>>n>>k>>l;
    f[0]=1;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    for (int i=0;i<=n;i++){
        rf[i]=binpow(f[i],mod-2);
    }
    vector<ll>A(1,1);
    vector<ll>good={0,2,mod-2};
    for (int i=1;i<=k;i++) A=mult(A,good);
    vector<ll>B(1,1);
    vector<ll>bad={1,mod-2,2};
    vector<ll>ans;
    for (int i=k;i<=n;i++){
        vector<ll>cur=B;
//        cout<<i<<" "<<C(i-1,k-1)<<" "<<C(i,k)<<endl;
        for (auto &j:cur) j=(j*C(i-1,k-1))%mod;
        ans=add(ans,cur);
        B=mult(B,bad);
    }
    ans=mult(ans,A);
    ll res=0ll;
    for (int i=0;i<ans.size();i++){
        res+=ans[i]*binpow(i+1,mod-2);
        res%=mod;
    }
    cout<<res*l%mod<<endl;
    return 0;
}
///0 0 20 -120 420 -1040 1904 -2624 2720 -2080 1120 -384 64