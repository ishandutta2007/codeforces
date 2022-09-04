#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
int MOD=1000000000+7;
int INF=1e6;

using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    int d[110000][200];
    rep(i,110000){
        fill(d[i],d[i]+200,MOD);
    }
    vector<int> map[110000];
    int g[110000];
    rep(i,n){
        scanf("%d",&g[i]);
    }
    rep(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a-1].push_back(b-1);
        map[b-1].push_back(a-1);
    }
    rep2(i,1,k){
        vector<int> goods;
        rep(j,n){
            if(g[j]==i) goods.push_back(j);
        }
        queue<int> bfs;
        rep(j,goods.size()){
            d[goods[j]][i]=0;
            bfs.push(goods[j]);
        }
        int turn=1;
        while(!bfs.empty()){
            int num=bfs.size();
            rep(j,num){
                int temp=bfs.front();
                bfs.pop();
                int num2=map[temp].size();
                rep(ii,num2){
                    if(d[map[temp][ii]][i]==MOD){
                        bfs.push(map[temp][ii]);
                        d[map[temp][ii]][i]=turn;
                    }
                }
            }
            turn++;
        }
    }
    
    rep(i,n){
        sort(d[i]+1,d[i]+(k+1));
        int ans=0;
        rep2(j,1,s){
            ans+=d[i][j];
        }
        printf("%d ",ans);
    }
    return 0;
    
}