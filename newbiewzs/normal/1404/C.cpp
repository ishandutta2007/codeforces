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
int n,q,a[N],bj[N],pre[N],x,y;
struct node{
	int x,y,id;
}qq[N];
int ans[N];
int cmp(node x,node y){
	return x.x<y.x;
}
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int summ[N*4],maxx[N*4],tag[N*4];
void update(int u){
	summ[u]=summ[ls]+summ[rs];
	maxx[u]=max(maxx[ls],maxx[rs]);
}
void pushdown(int u){
	if(tag[u]){
		maxx[ls]+=tag[u];
		maxx[rs]+=tag[u];
		tag[ls]+=tag[u];
		tag[rs]+=tag[u];
		tag[u]=0;
	}
}
void build(int u,int l,int r){
	if(l==r){
		maxx[u]=pre[l];
		if(bj[l])maxx[u]=-1e9;
		else summ[u]=1;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
}
void add(int u,int l,int r,int L,int R){
	if(L>R)return ;
	if(L<=l && R>=r){
		maxx[u]++;
		tag[u]++;
		if(l==r){
			if(maxx[u]>0){
				summ[u]=0;
				maxx[u]=-1e9;
				bj[l]=1;
				add(1,1,n,l+1,n);
			}
			return ;
		}
		if(maxx[u]>0){
		//	pushdown(u);
			tag[u]--;
			pushdown(u);
			add(ls,l,mid,L,R);
			add(rs,mid+1,r,L,R);
			update(u);
		}
		return ;
	}
	pushdown(u);
	if(L<=mid)add(ls,l,mid,L,R);
	if(R>mid)add(rs,mid+1,r,L,R);
	update(u);
}
void clear(int u,int l,int r,int x){
	if(l==r){
		maxx[u]=-1e9;
		summ[u]=0;
		return ;
	}
	pushdown(u);
	if(x<=mid)clear(ls,l,mid,x);
	else clear(rs,mid+1,r,x);
	update(u);
}
int query(int u,int l,int r,int L,int R){
	if(L<=l && R>=r){
		return summ[u];
	}
	pushdown(u);
	if(R<=mid)return query(ls,l,mid,L,R);
	if(L>mid)return query(rs,mid+1,r,L,R);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	/*for(int i=1;i<=n;i++){
		cout<<i-a[i]<<" ";
	}
	cout<<'\n';*/
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(i-a[i]<0){
			bj[i]=1;
		}
		else{
			if((i-a[i])-tmp<=0){
				pre[i]=(i-a[i]-tmp);
				tmp++;
			}
			else{
				bj[i]=1;
			}
		}
	}
	build(1,1,n);
	for(int i=1;i<=q;i++){
		x=read();y=read();
		qq[i]={x,y,i};
	}
	sort(qq+1,qq+q+1,cmp);
	int head=1;
	for(int i=1;i<=q;i++){
		while(head<n && head<=qq[i].x){
			if(!bj[head]){
				add(1,1,n,head+1,n);
			}
			clear(1,1,n,head);
			head++;
		}
		ans[qq[i].id]=query(1,1,n,1,n-qq[i].y);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}