///kk
#include<cstdio>
#include<map>
#define lg(x) (31-__builtin_clz(x))
#define llg(x) (63-__builtin_clzll(x))
using std::map;
const int N=500086,MOD=998244353;
const long long INF=1e18;
int tot,ec,anss,fa[N];
long long rans=INF;
struct point{int x,y;point(){}point(int _x,int _y){x=_x;y=_y;}}p[N];
struct edge{int u,v,w;edge(){}edge(int _u,int _v,int _w){u=_u;v=_v;w=_w;}}e[N];
map<int,bool>mx,my;
int Abs(int x){return x<0?-x:x;}
int lowbit(int x){return x&(-x);}
int Max(int a,int b){return a>b?a:b;}
int Min(int a,int b){return a<b?a:b;}
int Swap(int &a,int &b){a^=b^=a^=b;return true;}
int Add(int &a,int b){return(a+=b)>=MOD?a-=MOD:a;}
int vAdd(int a,int b){return(a+=b)>=MOD?a-=MOD:a;}
int Sub(int &a,int b){return(a-=b)<0?a+=MOD:a;}
int vSub(int a,int b){return(a-=b)<0?a+=MOD:a;}
int Mul(int a,int b){return 1ll*a*b%MOD;}
int qpow(int a,int b){
	int ret=1;
	while(b){if(b&1)ret=Mul(ret,a);a=Mul(a,a);b>>=1;}
	return ret;
}
int read(){
	char ch=getchar();int nn=0,ssss=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ssss*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){nn=nn*10+(ch-'0');ch=getchar();}
	return nn*ssss;
}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	tot=3;
	for(int i=1;i<=3;i++){
		p[i].x=read();p[i].y=read();
		mx[p[i].x]=true;my[p[i].y]=true;
	}
	for(map<int,bool>::iterator ix=mx.begin();ix!=mx.end();ix++)
		for(map<int,bool>::iterator iy=my.begin();iy!=my.end();iy++){
			if(ix->first==p[1].x&&iy->first==p[1].y)continue;
			if(ix->first==p[2].x&&iy->first==p[2].y)continue;
			if(ix->first==p[3].x&&iy->first==p[3].y)continue;
			p[++tot]=point(ix->first,iy->first);
		}
	int dx=0,dy=0;
	if(mx.size()==3)dx=Abs(mx.begin()->first-(prev(mx.end())->first));
	if(my.size()==3)dy=Abs(my.begin()->first-(prev(my.end())->first));
	for(int i=1;i<=tot;i++)
		for(int j=i+1;j<=tot;j++){
			if(p[i].x!=p[j].x&&p[i].y!=p[j].y)continue;
			if(p[i].x==p[j].x&&Abs(p[i].y-p[j].y)!=dy)e[ec++]=edge(i,j,Abs(p[i].y-p[j].y));
			if(p[i].y==p[j].y&&Abs(p[i].x-p[j].x)!=dx)e[ec++]=edge(i,j,Abs(p[i].x-p[j].x));
		}
	for(int S=1;S<(1<<ec);S++){
		for(int i=1;i<=tot;i++)fa[i]=i;
		long long ans=0;
		for(int i=S;i;i^=lowbit(i)){
			int x=lg(lowbit(i));
			int xx=getfa(e[x].u),yy=getfa(e[x].v);
			fa[xx]=yy;ans+=e[x].w;
		}
		if(getfa(1)!=getfa(2)||getfa(2)!=getfa(3)||getfa(1)!=getfa(3))continue;
		if(rans>ans){rans=ans;anss=S;}
	}
	printf("%d\n",__builtin_popcount(anss));
	for(int i=0;i<ec;i++){
		if(!((anss>>i)&1))continue;
		printf("%d %d %d %d\n",p[e[i].u].x,p[e[i].u].y,p[e[i].v].x,p[e[i].v].y);
	}
}