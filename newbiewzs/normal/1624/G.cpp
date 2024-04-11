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
	#ifdef WIN
		#include<windows.h>
		int cnt=0;
		template<typename T>
		T debug(T x){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		  	cerr<<x<<" ";
		  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		template<typename T,typename ...Types>
		void debug(T x,Types ... y){
			cnt++;int tmp=cnt;
			debug(x);
			debug(y...);
			if(tmp==cnt)cerr<<'\n';
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
const int N=2e5+5;
int f[N],siz[N];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	if(siz[x]<siz[y])swap(x,y);
	f[y]=x;siz[x]+=siz[y];
}
struct node{
	int x,y,z,t;
}a[N];
int top,head;
int n,m,T;
int cmp(node x,node y){
	return x.t<y.t;
}
bool check(int u){
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(int i=1;i<=top;i++){
		if((a[i].z&u)==a[i].z){
			merge(a[i].x,a[i].y);
		}
	}
	if(siz[find(1)]==n)return 1;
	return 0;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=m;i++){
			a[i].x=read();a[i].y=read();a[i].z=read();
		}
		top=m;
		int S=0,pre=31;
		for(int i=1;i<=30;i++){
			if(check(S))break;
			for(int k=1;k<=m;k++){
				bool flag=0;
				for(int j=pre;j<=30;j++){
					if((a[k].z&(1<<(j-1))) && !(S&(1<<(j-1))))flag=1;
				}
				if(flag){
					a[k].t=1e9;
					continue;
				}
				a[k].t=0;
				for(int j=1;j<pre;j++){
					if(a[k].z&(1<<(j-1)))a[k].t=j;
				}
			}
			sort(a+1,a+m+1,cmp);
			for(int k=1;k<=n;k++)f[k]=k,siz[k]=1;
			int head=1;
			for(int k=1;k<pre;k++){
				while(head<=m && a[head].t<=k){
					merge(a[head].x,a[head].y);
					head++;
				}
				if(siz[find(1)]==n){
					S|=(1<<(k-1));
					pre=k;
					break;
				}
			}
		}
		cout<<S<<'\n';
	}
	return 0;
}