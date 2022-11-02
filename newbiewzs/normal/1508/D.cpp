#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=2005;
int n,x[N],y[N],p[N];
int top,sx[N*N],sy[N*N];
void link(int u,int v){
	swap(p[u],p[v]);
	sx[++top]=u;sy[top]=v;
}
int f[N],siz[N],pos,xx=1e9,yy=1e9;
inline int find(const int &x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return ;
	if(siz[x]<siz[y])swap(x,y);
	f[y]=x;siz[x]+=siz[y];
}
struct node{
	int id;
	double val;
}a[N];
int tot;
inline int cmp(const node &x,const node &y){
	return x.val<y.val;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
//	cout<<atan2(-10,10)<<" "<<atan2(-5,15)<<" "<<atan2(0,15)<<" "<<atan2(5,15)<<" "<<atan2(15,0);
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();p[i]=read();
	}
	for(int i=1;i<=n;i++){
		if(p[i]==i)continue;
		if(x[i]<xx){
			pos=i;
			xx=x[i];yy=y[i];
		}
		else if(x[i]==xx && y[i]<yy){
			pos=i;
			xx=x[i];yy=y[i];
		}
	}
	if(!pos){
		puts("0");return 0;
	}
	for(int i=1;i<=n;i++){
		if(i==pos){
			a[i].id=i;
			a[i].val=-11111111;
		}
		else{
			a[i].id=i;
			a[i].val=atan2(y[i]-y[pos],x[i]-x[pos]);
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(int i=1;i<=n;i++){
		merge(p[i],i);
	}
	for(int i=2;i<n;i++){
		if(find(a[i].id)!=find(a[i+1].id)){
			link(a[i].id,a[i+1].id);
			merge(a[i].id,a[i+1].id);
		}
	}
	while(1){
		if(p[pos]==pos)break;
		link(pos,p[pos]);
	}
	cout<<top<<'\n';
	for(int i=1;i<=top;i++){
		cout<<sx[i]<<" "<<sy[i]<<'\n';
	}
	return 0;
}