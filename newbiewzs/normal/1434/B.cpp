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
const int N=3e5+5;
int n,x[N],pos[N],jl[N],pm[N];
string c[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int summ[N*4];
void add(int u,int l,int r,int x,int k){
	if(l==r){
		summ[u]+=k;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	else add(rs,mid+1,r,x,k);
	summ[u]=summ[ls]+summ[rs];
}
int ask(int u,int l,int r,int L,int R){
	if(L<=l && R>=r){
		return summ[u];
	}
	if(R<=mid)return ask(ls,l,mid,L,R);
	if(L>mid)return ask(rs,mid+1,r,L,R);
	return ask(ls,l,mid,L,R)+ask(rs,mid+1,r,L,R);
}
int query(int u,int l,int r,int x){
	if(x<l)return -1;
	if(!summ[u])return -1;
	if(l==r){
		if(summ[u])return l;
	}
	if(x>mid && ask(1,1,n*2,mid+1,x)){
		return query(rs,mid+1,r,x);
	}
	return query(ls,l,mid,x);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	int tot=0;
	for(int i=1;i<=2*n;i++){
		cin>>c[i];
		if(c[i]=="-"){
			x[i]=read();
			pos[x[i]]=i;
		}
		else{
			add(1,1,2*n,i,1);
			pm[i]=++tot;
		}
	}
	for(int i=1;i<=n;i++){
		int tmp=query(1,1,2*n,pos[i]);
		if(tmp==-1){
			puts("NO");
			return 0;
		}
		add(1,1,2*n,tmp,-1);
		jl[pm[tmp]]=i;
	}
	set<int>s;
	for(int i=1;i<=2*n;i++){
		if(c[i]=="-"){
			auto tmp=s.begin();
			if(*tmp!=x[i]){
				puts("NO");
				return 0;
			}
			s.erase(tmp);
		}
		else{
			s.insert(jl[pm[i]]);
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		cout<<jl[i]<<" ";
	}
	return 0;
}