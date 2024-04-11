#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<P<int,int> > v[45];
int n,m,k,g[1005][1005],d[45][1005][1005];
int fx[4][2]={1,0,-1,0,0,1,0,-1};
void put(queue<P<int,int> > &q,int color,P<int,int> p,int dist){
    if(dist<d[color][p.F][p.S]){
        d[color][p.F][p.S]=dist;
        q.push(p);
    }
}
bool check(int x,int y){RE x>=1&&x<=n&&y<=m&&y>=1;}
void bfs(int color){
    queue<P<int,int> > q;
    FILL(d[color],0x3f);
    for(int i=0;i<v[color].size();i++)put(q,color,v[color][i],0);
    P<int,int> cur;int x,y;
    bool fco[45]={};
    while(!q.empty()){
        cur=q.front();q.pop();
        if(!fco[g[cur.F][cur.S]]){
            for(int i=0;i<v[g[cur.F][cur.S]].size();i++)
                put(q,color,v[g[cur.F][cur.S]][i],d[color][cur.F][cur.S]+1);
            fco[g[cur.F][cur.S]]=1;
        }
        for(int i=0;i<4;i++){
            x=cur.F;y=cur.S;
            x+=fx[i][0];y+=fx[i][1];
            if(check(x,y))put(q,color,MP(x,y),d[color][cur.F][cur.S]+1);
        }
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
    FOR(i,1,n){
        FOR(j,1,m){
            cin>>g[i][j];
            v[g[i][j]].PB(MP(i,j));
        }
    }
    FOR(i,1,k)bfs(i);
    int q;
    cin>>q;
    int c1,c2,r1,r2,co1,co2,ans,cl[45];
    FOR(i,1,q){
        cin>>r1>>c1>>r2>>c2;
        co1=g[r1][c1];
        co2=g[r2][c2];
        ans=min(d[co1][r2][c2],d[co2][r1][c1])+1;
        ans=min(ans,abs(c1-c2)+abs(r1-r2));
        FILL(cl,0x3f);
        FOR(r,max(1,r1-ans+1),min(n,r1+ans-1)){
            FOR(c,max(1,c1-ans+1),min(m,c1+ans-1)){
                cl[g[r][c]]=min(cl[g[r][c]],abs(r-r1)+abs(c-c1));
            }
        }
        FOR(co,1,k){
            ans=min(ans,cl[co]+1+d[co][r2][c2]);
        }
        cout<<ans<<'\n';
    }
	RE 0;
}