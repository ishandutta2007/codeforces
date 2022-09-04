#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=1e9+7;
int INF=1e6;
ll int MAX_N=1e18;
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

       
main(){
    int n,p;
    cin>>n>>p;
    int a[3000];
    rep(i,n){
        char c;
        cin>>c;
        if(c=='0') a[i]=0;
        else if(c=='1') a[i]=1;
        else a[i]=2;
    }
    bool flag=true;
    rep(i,n-p){
        if(a[i]==2) {flag=false; if(a[i+p]==2) {a[i]=0;a[i+p]=1;}
        else{
        a[i]=(a[i+p]^1);}}
        if(a[i]!=a[i+p]) {flag=false; if(a[i+p]==2) a[i+p]=(a[i]^1);}
    }
    if(flag) { cout<<"No"; return 0;}
    rep(i,n){
        if(a[i]!=2) cout<<a[i];
        else cout<<0;
    }
    return 0;
}