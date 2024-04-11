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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	#ifdef WIN
		#include<windows.h>
		int cnttt=0;
		template<typename T>
		T debug(T x){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		  	cerr<<x<<" ";
		  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		template<typename T,typename ...Types>
		void debug(T x,Types ... y){
			cnttt++;int tmp=cnttt;
			debug(x);
			debug(y...);
			if(tmp==cnttt)cerr<<'\n';
		}
	#else
		// Linux
		/*#define Green \033[32m
		#define Reset \033[0m\n
		void debug(int x){
			cout<<"Green"<<x<<"Reset";
		}*/
	#endif
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
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
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
const int N=5e5+5;
int n,m,k,c[N];
struct node{
	int x,y,fx,fy;
}a[N*2];
int cmp(node x,node y){
	if(x.fx!=y.fx)return x.fx<y.fx;
	else return x.fy<y.fy;
}
int siz[N*2],bj[N*2],f[N*2];
int find(int x){
	if(f[x]!=x)return find(f[x]);
	else return x;
}
int sx[N*4],sy[N*4],flag,top;
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	if(siz[y]>siz[x])swap(x,y);
	f[y]=x;siz[x]+=siz[y];
	sx[++top]=x;sy[top]=y;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		c[i]=read();f[i]=i;f[i+n]=i+n;
	}
	for(int i=1;i<=k;i++)bj[i]=1;
	for(int i=1;i<=m;i++){
		a[i].x=read();
		a[i].y=read();
		a[i].fx=c[a[i].x];
		a[i].fy=c[a[i].y];
		if(a[i].fx>a[i].fy){
			swap(a[i].x,a[i].y);
			swap(a[i].fx,a[i].fy);
		}
		if(a[i].fx==a[i].fy){
			if(find(a[i].x)==find(a[i].y))bj[a[i].fx]=0;
			merge(a[i].x,a[i].y+n);
			merge(a[i].x+n,a[i].y);
		}
	}
	sort(a+1,a+m+1,cmp);
	int ans=(k*(k-1)/2);
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(!bj[i])ans=ans-(k-1),cnt++;
	}
	ans=ans+(cnt*(cnt-1)/2);
	for(int i=1;i<=m;){
		if(a[i].fx==a[i].fy){
			i++;continue;
		}
		if(!bj[a[i].fx] || !bj[a[i].fy]){
			i++;continue;
		}
		int head=i;
		while(a[head+1].fx==a[i].fx && a[head+1].fy==a[i].fy)head++;
		top=0;flag=1;
		if(!bj[a[i].fx] || !bj[a[i].fy])flag=0;
		for(int kk=i;kk<=head;kk++){
			if(find(a[kk].x)==find(a[kk].y))flag=0;
			merge(a[kk].x,a[kk].y+n);
			merge(a[kk].x+n,a[kk].y);
		}
		if(!flag)ans--;
		while(top){
			siz[sx[top]]-=siz[sy[top]];
			f[sy[top]]=sy[top];
			top--;
		}
		i=head+1;
	}
	cout<<ans;
	return 0;
}