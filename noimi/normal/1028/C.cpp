#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=998244353;
#define INF 2*1e9
#define N 210000
using namespace std;
main(){
    int n;
    cin>>n;
    int x[N][2],y[N][2];
    cin>>x[0][0]>>x[0][1]>>y[0][0]>>y[0][1];
    int a,b,c,d;
    a=x[0][0];
    b=x[0][1];
    c=y[0][0];
    d=y[0][1];
    int mem,flag=2;
    rep2(i,1,n-1){
        cin>>x[i][0]>>x[i][1]>>y[i][0]>>y[i][1];
        int p,q,r,s;
        p=x[i][0];q=x[i][1];r=y[i][0];s=y[i][1];
        int A=a,B=b,C=c,D=d;
        a=max(a,p);b=max(q,b);c=min(c,r);d=min(d,s);
        if(a>c||b>d) {
            if(flag==2){mem=i;flag=1;a=A;b=B;c=C;d=D;}
            else if(flag==1){
                flag=0;
            }
        }
    }
    if(flag){
        cout<<a<<" "<<b;return 0;
    }
    a=x[mem][0];b=x[mem][1];c=y[mem][0];d=y[mem][1];
    flag=2;
    rep2(i,0,n-1){
        int p,q,r,s;
        p=x[i][0];q=x[i][1];r=y[i][0];s=y[i][1];
        int A=a,B=b,C=c,D=d;
        a=max(a,p);b=max(q,b);c=min(c,r);d=min(d,s);
        if(a>c||b>d) {
            if(flag==2){mem=i;flag=1;a=A;b=B;c=C;d=D;}
            else if(flag==1){
                flag=0;
            }
        }
    }
    cout<<a<<" "<<b;return 0;    
}