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
string s[505];
int n,m,rmax[505][505][505],lmax[505][505];
void solve1(){
    int t[505][505];
    FILL(t,0);
    rep(i,0,n)
        rep(j,0,m)
            if(s[i][j]=='R')
                t[i+1][j+1]=min(min(t[i+1][j],t[i][j+1]),t[i][j])+1;
    rep(i,0,n)
        rep(j,0,m)lmax[i][j]=t[i][j];
    FILL(t,0);
    rep(i,0,n)
        for(int j=m-1;j>=0;j--)
            if(s[i][j]=='G')
                t[i+1][j]=min(min(t[i][j],t[i][j+1]),t[i+1][j+1])+1;
    rep(i,0,n)
        rep(j,0,m)lmax[i][j]=min(lmax[i][j],t[i][j]);
    FILL(t,0);
    for(int i=n-1;i>=0;i--)
        for(int j=m-1;j>=0;j--)
            if(s[i][j]=='B')
                t[i][j]=min(min(t[i+1][j],t[i+1][j+1]),t[i][j+1])+1;
    rep(i,0,n)
        rep(j,0,m)lmax[i][j]=min(lmax[i][j],t[i][j]);
    FILL(t,0);
    for(int i=n-1;i>=0;i--)
        rep(j,0,m)
            if(s[i][j]=='Y')
                t[i][j+1]=min(min(t[i+1][j],t[i+1][j+1]),t[i][j])+1;
    rep(i,0,n)
        rep(j,0,m)lmax[i][j]=min(lmax[i][j],t[i][j]);
}
void solve2(){
    rep(i,0,n)
        rep(l,0,m){
            deque<P<int,int> > q;
            FOR(r,l+1,m){
                int len=min(lmax[i][r-1],r-l-1);
                if(q.empty()||q.back().F<len)q.PB(MP(len,r-1));
                while(q.size()>1&&min(q[0].F,r-q[0].S)<=min(q[1].F,r-q[1].S))q.pop_front();
                rmax[i][l][r]=min(q[0].F,r-q[0].S);
            }
        }
}
void solve3(int x1,int y1,int x2,int y2){
    int ans=0;
    rep(i,x1,x2){
        ans=max(ans,min(min(rmax[i][y1][y2],i-x1),x2-i));
    }
    printf("%d\n",ans*ans*4);
}
int main(){
	int q,x1,x2,y1,y2;
    scanf("%d%d%d",&n,&m,&q);
    rep(i,0,n)cin>>s[i];
    solve1();
    solve2();
    FOR(i,1,q){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1--;y1--;
        solve3(x1,y1,x2,y2);
    }
	RE 0;
}