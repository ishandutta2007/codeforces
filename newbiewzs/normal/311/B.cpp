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
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
#define dsi(x,y,z) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<" the "<<#z<<" = "<<z<<'\n';
#define fer(i,a,b) for(int i=a;i<=b;i++)
#define erf(i,a,b) for(int i=b;i>=a;i--)
// #pragma GCC optimize(3)
#define int long long
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
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
/*namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;*/
char aa;
const int N=1e5+5;
int n,m,p,d[N],h[N],t[N];
int s[N];
int cmp(int x,int y){
	return t[x]<t[y];
}
int f[2][100005];
int q[50005],head,tail;
char bb;
signed main(){
	#ifdef newbiewzs
//		dbg((&bb-&aa)/1024/1024);
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();p=read();
	for(int i=2;i<=n;i++)d[i]=d[i-1]+read();
	for(int i=1;i<=m;i++){
		h[i]=read();t[i]=read()-d[h[i]];
	}
	sort(t+1,t+m+1);
	mem0x3f(f);
	for(int i=1;i<=m;i++){
		s[i]=s[i-1]+t[i];
	}
	for(int i=1;i<=m;i++)f[1][i]=i*t[i]-s[i];
	//return 0;
	for(int i=2;i<=p;i++){
		head=1;tail=0;
		q[++tail]=i-1;
		int ne=(i%2);
		int pr=(ne^1);
		mem0(f[ne]);
		for(int k=i;k<=m;k++){
			/*if(i==2 && k==6){
				new char;
			}*/
			while(head<tail && (f[pr][q[head+1]]+s[q[head+1]])-(f[pr][q[head]]+s[q[head]])<=t[k]*(q[head+1]-q[head]))head++;
			//if(i==2 && k==m)head=3;
			f[ne][k]=k*t[k]-s[k]+f[pr][q[head]]+s[q[head]]-q[head]*t[k];
			while(head<tail && ((f[pr][k]+s[k])-(f[pr][q[tail]]+s[q[tail]]))*(q[tail]-q[tail-1])<=((f[pr][q[tail]]+s[q[tail]])-(f[pr][q[tail-1]]+s[q[tail-1]]))*(k-q[tail]) )tail--;
			q[++tail]=k;
		}
	//	dbg(i);
	}
	int ans=f[p&1][m];
//	for(int i=1;i<=p;i++)ans=min(ans,f[i][m]);
 	cout<<ans;
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}