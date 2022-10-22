#include<iostream>
typedef long long ll;
typedef std::pair<ll,ll> pll;
#define MAXN 1011
ll d1[MAXN][MAXN],d2[MAXN][MAXN],n,m,INF=ll(1e11);
pll q[MAXN*MAXN];
ll mx[]={-1,-2,-2,-1,1,2,2,1},my[]={2,1,-1,-2,-2,-1,1,2};
void bfs(ll sx,ll sy,ll dis[][MAXN])
{
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)dis[i][j]=INF;
    dis[sx][sy]=0;
    ll h=1,t=1;
    q[t++]=pll(sx,sy);
    while(h<t)
    {
        ll x=q[h].first,y=q[h].second;++h;
        for(ll i=0;i<8;++i)
        {
            ll vx=x+mx[i],vy=y+my[i];
            if(vx>0&&vx<=n&&vy>0&&vy<=m&&dis[vx][vy]>dis[x][y]+1)
            {
                dis[vx][vy]=dis[x][y]+1;q[t++]=pll(vx,vy);
            }
        }
    }
}
void print(ll sx,ll sy,ll dis[][MAXN])
{
    for(ll i=0;i<8;++i)
    {
        ll vx=sx+mx[i],vy=sy+my[i];
        if(vx>0&&vx<=n&&vy>0&&vy<=m&&dis[vx][vy]<dis[sx][sy])
        {
            std::cout<<vx<<" "<<vy<<std::endl;
            print(vx,vy,dis);return;
        }
    }
}
int main()
{
    std::cin>>n>>m;
    ll x1,y1,x2,y2;std::cin>>x1>>y1>>x2>>y2;
    bfs(n/2,m/2,d1),bfs(n/2+1,m/2,d2);
    ll w_w=d1[x1][y1],w_b=d2[x1][y1];
    ll b_w=d1[x2][y2],b_b=d2[x2][y2];
    if((x1+y1)%2==(x2+y2)%2)//the second captures the first
    {
        if(b_b<w_w){puts("BLACK");print(x2,y2,d2);return 0;}
        if(b_w<w_w+1){puts("BLACK");print(x2,y2,d1);print(n/2,m/2,d2);return 0;}
        puts("WHITE");print(x1,y1,d1);return 0;
    }
    //else,the first captures the second
    if(w_w<=b_b){puts("WHITE");print(x1,y1,d1);return 0;}
    if(w_b<=b_b+1){puts("WHITE");print(x1,y1,d2);print(n/2+1,m/2,d1);return 0;}
    puts("BLACK");print(x2,y2,d2);
    return 0;
}