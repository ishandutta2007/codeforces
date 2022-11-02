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
		int cntt=0;
		template<typename T>
		T debug(T x){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		  	cerr<<x<<" ";
		  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		template<typename T,typename ...Types>
		void debug(T x,Types ... y){
			cntt++;int tmp=cntt;
			debug(x);
			debug(y...);
			if(tmp==cntt)cerr<<'\n';
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
int T;
int a[10],n,b[N],st[N][7],cnt,head[N],ans=1e15;
struct node{
	int id,pos,val;
}s[N*6];
int cmp(node x,node y){
	return x.val<y.val;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	for(int i=1;i<=6;i++)a[i]=read();
	sort(a+1,a+6+1);
	reverse(a+1,a+6+1);
	n=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++){
		for(int k=1;k<=6;k++){
			st[i][k]=b[i]-a[k];
			s[++cnt].id=i;
			s[cnt].pos=k;
			s[cnt].val=b[i]-a[k];
		}
	}
	sort(s+1,s+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		while(head[i]<6 && st[i][head[i]]<s[1].val)head[i]++;
	}
	int maxx=0;
	for(int i=1;i<=n;i++)maxx=max(maxx,st[i][head[i]]);
	for(int i=1;i<=cnt;i++){
		ans=min(ans,maxx-s[i].val);
		if(ans==0){
			new char;
		}
		if(head[7]==4){
			new char;
		}
		if(i==cnt)continue;
		if(s[i].val!=s[i+1].val){
			bool flag=0;
			for(int k=i;k>=1;k--){
				if(s[i].val!=s[k].val)break;
				while(head[s[k].id]<6 && st[s[k].id][head[s[k].id]]<s[i+1].val){
					head[s[k].id]++;
					maxx=max(maxx,st[s[k].id][head[s[k].id]]);
				}
				if(st[s[k].id][head[s[k].id]]<s[i+1].val){
					flag=1;break;
				}
			}
			if(flag)break;
		}
		
	}
	cout<<ans;
	return 0;
}