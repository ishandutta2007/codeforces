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
    ll int n,lenth,w;
    cin>>n>>lenth>>w;
    ll int r[110000],l[110000],r1[110000],l1[110000];
    ll int rn=0,ln=0;
    rep(i,n){
        ll int x,v;
        cin>>x>>v;
        if(v==1){
            r[rn]=(w+1)*x-(w-1)*lenth;
            r1[rn]=(w-1)*x-(w+1)*lenth;
            rn++;
        }
        else{
            l[ln]=(w-1)*x;
            l1[ln]=(w+1)*x;
            ln++;
        }
    }
        sort(l,l+ln); sort(l1,l1+ln);
        ll int ans=0;
        rep(i,rn){
            ll int m=upper_bound(l,l+ln,r[i])-l;
            ll int m2=upper_bound(l1,l1+ln,r1[i])-l1;
            m=max(m,m2);
            ans+=ln-m;
        }
        cout<<ans;
}