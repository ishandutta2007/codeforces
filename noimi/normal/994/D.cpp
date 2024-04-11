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
    int n,m;
    cin>>n>>m;
    vector<pii> v1,v2;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        v1.push_back({max(a,b),min(a,b)});
    }
    rep(i,m){
        int a,b;
        cin>>a>>b;
        v2.push_back({max(a,b),min(a,b)});
    }
    int temp=-INF;
    int flag=0;
    rep(i,n){
        rep(j,m){
            int s=v1[i].first,t=v1[i].second,u=v2[j].first,
            v=v2[j].second;
            if(s==u&&t==v) continue;
            if(s==u){
                if(temp==-INF||temp==s) temp=s;
                else flag=1;
            }
            if(s==v){
                if(temp==-INF||temp==s) temp=s;
                else flag=1;
            }
            if(t==u){
                if(temp==-INF||temp==t) temp=t;
                else flag=1;
            }
            if(t==v){
                if(temp==-INF||temp==t) temp=t;
                else flag=1;
            }
        }
    }
    if(!flag){ cout<<temp; return 0;}
    flag=0;
    rep(i,n){
        temp=-INF;
        rep(j,m){
            int s=v1[i].first,t=v1[i].second,u=v2[j].first,
            v=v2[j].second;
            if(s==u&&t==v) continue;
            if(s==u){
                if(temp==-INF||temp==s) temp=s;
                else flag=1;
            }
            if(s==v){
                if(temp==-INF||temp==s) temp=s;
                else flag=1;
            }
            if(t==u){
                if(temp==-INF||temp==t) temp=t;
                else flag=1;
            }
            if(t==v){
                if(temp==-INF||temp==t) temp=t;
                else flag=1;
            }
        }
    }
    rep(j,m){
        temp=-INF;
        rep(i,n){
            int s=v1[i].first,t=v1[i].second,u=v2[j].first,
            v=v2[j].second;
            if(s==u&&t==v) continue;
            if(s==u){
                if(temp==-INF||temp==s) temp=s;
                else flag=1;
            }
            if(s==v){
                if(temp==-INF||temp==s) temp=s;
                else flag=1;
            }
            if(t==u){
                if(temp==-INF||temp==t) temp=t;
                else flag=1;
            }
            if(t==v){
                if(temp==-INF||temp==t) temp=t;
                else flag=1;
            }
        }
    }
    if(flag) { cout<<-1; return 0;}
    else cout<<0;
    return 0;
}