#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

main(){
    int n,m;
    cin>>n>>m;
    int count[210000]={};
    vector<pair<int,int>> v;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        count[a]++;
        count[b]++;
        pair<int,int> p;
        p.first=a;
        p.second=b;
        v.push_back(p);
    }
    int map[210000][2]={};
    rep(i,m){
        if(count[v[i].first]==2&&count[v[i].second]==2){
            if(map[v[i].first][0]==0) map[v[i].first][0]=v[i].second;
            else map[v[i].first][1]=v[i].second;
            if(map[v[i].second][0]==0) map[v[i].second][0]=v[i].first;
            else map[v[i].second][1]=v[i].first; 
        }
    }
    int flag[210000]={};
    rep(i,210000){
        if(count[i]!=2) flag[i]++;
    }
    int ans=0;
    rep(i,210000){
        if(!flag[i]){
            flag[i]++;
            int now=map[i][0];
            int pre=i;
            while(now!=i){
                if(flag[now]){
                    ans--;
                    break;
                }
                flag[now]=1;
                if(map[now][0]==pre){
                    pre=now;
                    now=map[now][1];
                    
                }
                else{
                    pre=now;
                    now=map[now][0];
                    
                }
            }
            ans++;
        }
    }
    cout<<ans;
    return 0;
}