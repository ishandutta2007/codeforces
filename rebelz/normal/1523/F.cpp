#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll xb,yb,t;
	bool operator<(const node c)const{return t<c.t;}
}p[105];

const ll inf=1ll<<60;
int n,m;
ll xa[15],ya[15],dis1[105][17000],dis2[15][17000],d[17000][105],f[17000][105];

ll dist(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) xa[i]=readint(),ya[i]=readint();
	for(int i=1;i<=m;i++) p[i].xb=readint(),p[i].yb=readint(),p[i].t=readint();
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++){
		for(int j=0;j<(1<<n);j++){
			dis1[i][j]=inf;
			for(int k=1;k<=n;k++)
				if((j>>(k-1))&1)
					chkmin(dis1[i][j],dist(p[i].xb,p[i].yb,xa[k],ya[k]));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<n);j++){
			dis2[i][j]=inf;
			for(int k=1;k<=n;k++)
				if((j>>(k-1))&1)
					chkmin(dis2[i][j],dist(xa[i],ya[i],xa[k],ya[k]));
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++) d[(1<<(i-1))][0]=0;
	for(int i=1;i<=m;i++) f[0][i]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=m-1;j>=0;j--) chkmin(d[i][j],d[i][j+1]);
		for(int j=0;j<=m;j++)
			for(int k=1;k<=m;k++)
				if(dis1[k][i]+d[i][j]<=p[k].t) chkmax(f[i][k],(ll)j+1);
		for(int j=1;j<=m;j++)
			for(int k=j+1;k<=m;k++)
				if(f[i][j])
					if(min(dist(p[j].xb,p[j].yb,p[k].xb,p[k].yb),dis1[k][i])+p[j].t<=p[k].t)
						chkmax(f[i][k],f[i][j]+1);
		for(int j=0;j<=m;j++)
			for(int k=1;k<=n;k++)
				if(!((i>>(k-1))&1))
					chkmin(d[i^(1<<(k-1))][j],d[i][j]+dis2[k][i]);
		for(int j=1;j<=m;j++)
			if(f[i][j])
				for(int k=1;k<=n;k++)
					if(!((i>>(k-1))&1))
						chkmin(d[i^(1<<(k-1))][f[i][j]],p[j].t+min(dis2[k][i],dist(p[j].xb,p[j].yb,xa[k],ya[k])));
	}
	ll ans=0;
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=m;j++)
			chkmax(ans,f[i][j]);
	printf("%lld\n",ans);
	return 0;
}