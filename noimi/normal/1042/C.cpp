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
ll MOD=1e9+7;
#define INF 2*1e9
#define N 600010
#define MAX_V 900010
using namespace std;
main(){
    int n;cin>>n;
    int a[N];
    bool F=false;
    rep(i,n)cin>>a[i];
    int g=0,zero=0;
    rep(i,n){
        if(a[i]>0)F=true;
        if(a[i]<0)g++;
        if(a[i]==0)zero++;
    }
    int pre=INF;
    int pre2=INF;
    if(zero&&g%2){
        bool flag=true;
        int M=-INF;
        rep(i,n){
            if(a[i]<0)M=max(M,a[i]);
        }
        rep(i,n){
            if(a[i]==M&&flag){
                if(pre2!=INF){printf("%d %d %d\n",1,pre2,i+1);pre2=i+1;}
                else pre2=i+1;
                flag=false;
            }
            else if(a[i]==0){
                if(pre2!=INF){printf("%d %d %d\n",1,pre2,i+1);pre2=i+1;}
                else pre2=i+1;
            }
            else{if(pre!=INF)
                {printf("%d %d %d\n",1,pre,i+1);pre=i+1;}
                else pre=i+1;
            }
        }
        if(F||g>1)
        printf("%d %d",2,pre2);
        return 0;
    }
    if(zero&&g%2==0){
        rep(i,n){
            if(a[i]==0){
                if(pre2!=INF){printf("%d %d %d\n",1,pre2,i+1);pre2=i+1;}
                else pre2=i+1;
            }
            else{if(pre!=INF)
                {printf("%d %d %d\n",1,pre,i+1);pre=i+1;}
                else pre=i+1;
            }
        }
        if(F||g>1)
        printf("%d %d",2,pre2);
        return 0;
    }
    if(g%2){
        int M=-INF;
        rep(i,n){
            if(a[i]<0)M=max(M,a[i]);
        }
        bool flag=true;
        rep(i,n){
            if(a[i]==M&&flag){
                cout<<2<<" "<<i+1<<endl;
                flag=false;
            }
            else{if(pre!=INF)
                {printf("%d %d %d\n",1,pre,i+1);pre=i+1;}
                else pre=i+1;
            }
        }
        return 0;
    }
    if(g%2==0){
        int M=0;
        rep(i,n){
            if(a[i]>0)M=min(M,a[i]);
        }
        bool flag=true;
        rep(i,n){
            if(pre!=INF)
                {printf("%d %d %d\n",1,pre,i+1);pre=i+1;}
                else pre=i+1;
            }
        return 0;
    }
}