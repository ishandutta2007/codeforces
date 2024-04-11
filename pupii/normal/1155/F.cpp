// XZZ
#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int dp[1<<14],gdpS[1<<14],gdpx[1<<14],gdpy[1<<14];//gdp[S]:SSxy
int f[14][14][1<<14],gf[14][14][1<<14],gfS[14][14][1<<14];//gf[x][y][S]:y
int cnt[1<<14],st[1<<14];
int graph[15][15];
il vd chkf(int x,int y,int S,int newf,int gg,int SS){if(f[x][y][S]>newf)f[x][y][S]=newf,gf[x][y][S]=gg,gfS[x][y][S]=SS;}
il vd chkdp(int p,int newdp,int x,int y,int S){if(dp[p]>newdp){dp[p]=newdp,gdpS[p]=S,gdpx[p]=x,gdpy[p]=y;}}
il vd out_chain(int x,int y,int S){
	if(cnt[S]==1)return;
	printf("%d %d\n",y+1,gf[x][y][S]+1);
	out_chain(x,gf[x][y][S],gfS[x][y][S]);
}
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),u,v;
	while(m--)u=gi()-1,v=gi()-1,graph[u][v]=graph[v][u]=1;
	memset(dp,63,sizeof dp);
	memset(f,63,sizeof f);
	for(int i=1;i<1<<n;++i)cnt[i]=cnt[i^(i&-i)]+1,st[i]=i;
	std::sort(st,st+(1<<n),[&](const int&a,const int&b){return cnt[a]<cnt[b];});
	dp[0]=0;for(int i=0;i<n;++i)dp[1<<i]=0,f[i][i][1<<i]=0;
	for(int xi=1,i;xi<1<<n;++xi){
		i=st[xi];
		for(int x=0;x<n;++x){
			if(~i&(1<<x))continue;
			for(int y=0;y<n;++y){
				if(~i&(1<<y))continue;
				if(f[x][y][i]>1e6)continue;
				//printf("%d %d %d %d\n",x,y,i,f[x][y][i]);
				if(x==y&&cnt[i]>1)continue;
				for(int z=0;z<n;++z)
					if(graph[y][z]&&((x==z&&cnt[i]>2)||((1<<z)&~i)))
						chkf(x,z,i|(1<<z),f[x][y][i]+1,y,i);
			}
		}
	}
	for(int xi=1,i;xi<1<<n;++xi){
		i=st[xi];if(dp[i]>1e6)continue;//printf("%d %d\n",i,dp[i]);
		for(int x=0;x<n;++x){
			if(~i&(1<<x))continue;
			for(int y=0;y<n;++y){
				if(~i&(1<<y))continue;
				int U=((1<<n)-1)^i;
				for(int j=U;;j=(j-1)&U){
					chkdp(i|j,dp[i]+f[x][y][j|(1<<x)|(1<<y)],x,y,j|(1<<x)|(1<<y));
					if(!j)break;
				}
			}
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	int S=(1<<n)-1;
	while(cnt[S]>1)out_chain(gdpx[S],gdpy[S],gdpS[S]),S=(S^gdpS[S])|(1<<gdpx[S])|(1<<gdpy[S]);
	return 0;
}