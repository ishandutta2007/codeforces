#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=998244353;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int x1[4],y1[4],x2[4],y2[4];
    rep(i,4){
        cin>>x1[i]>>y1[i];
    }
    rep(i,4)cin>>x2[i]>>y2[i];
    rep(i,4){
        x1[i]+=100;
        y1[i]+=100;
        x2[i]+=100;
        y2[i]+=100;
    }
    int a=max({y1[0],y1[1],y1[2],y1[3]});
    int b=min({y1[0],y1[1],y1[2],y1[3]});
    int c=min({x1[0],x1[1],x1[2],x1[3]});
    int d=max({x1[0],x1[1],x1[2],x1[3]});
    int p=max({y2[0]-x2[0],y2[1]-x2[1],y2[3]-x2[3],y2[2]-x2[2]});
    int q=min({y2[0]-x2[0],y2[1]-x2[1],y2[3]-x2[3],y2[2]-x2[2]});
    int r=max({y2[0]+x2[0],y2[1]+x2[1],y2[3]+x2[3],y2[2]+x2[2]});
    int s=min({y2[0]+x2[0],y2[1]+x2[1],y2[3]+x2[3],y2[2]+x2[2]});
    int flag=0;
    rep(i,201){
        rep(j,201){
            if(s<=i+j&&i+j<=r&&q<=j-i&&j-i<=p){
                if(c<=i&&i<=d&&b<=j&&j<=a) flag=1;
            }
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}