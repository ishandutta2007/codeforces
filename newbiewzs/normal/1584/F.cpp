#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
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
const int N=11;
const int M=60;
int T,n,l[N],f[52][1<<10],pa[N][52],pb[N][52];
char a[N][M];
int cg(char c){
	if(c>='A' && c<='Z')return c-'A';
	else return c-'a'+26;
}
char fg(int x){
	if(x<26)return (char)(x+'A');
	else return (char)(x-26+'a');
}
int dp(int u,int s){
	if(f[u][s]!=-1)return f[u][s];
	int tmp=0;
	for(int i=0;i<52;i++){
		bool flag=1;
		int st=0;
		for(int k=1;k<=n;k++){
			int tmp=(s&(1<<(k-1)))?pb[k][u]:pa[k][u];
			if(pa[k][i]>tmp);
			else if(pb[k][i]>tmp)st|=(1<<(k-1));
			else {
				flag=0;
				break;
			}
		}
		if(flag){
			int ta=dp(i,st);
			if(ta>tmp){
				tmp=ta;
			}
		}
	}
	f[u][s]=tmp+1;
	return f[u][s];
}
void tp(int u,int s){
	cout<<fg(u);
	if(f[u][s]==1)return ;
	int tmp=0;
	for(int i=0;i<52;i++){
		bool flag=1;
		int st=0;
		for(int k=1;k<=n;k++){
			int tmp=(s&(1<<(k-1)))?pb[k][u]:pa[k][u];
			if(pa[k][i]>tmp);
			else if(pb[k][i]>tmp)st|=(1<<(k-1));
			else {
				flag=0;
				break;
			}
		}
		bool bj=0;
		if(flag){
			if(f[i][st]+1==f[u][s]){
				tp(i,st);
				bj=1;
			}
		}
		if(bj)break;
	}
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		memset(f,-1,sizeof(f));
		memset(pa,0,sizeof(pa));
		memset(pb,0,sizeof(pb));
		n=read();
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
			l[i]=strlen(a[i]+1);
			for(int k=1;k<=l[i];k++){
				if(!pa[i][cg(a[i][k])])pa[i][cg(a[i][k])]=k;
				else pb[i][cg(a[i][k])]=k;
			}
		}
		int ans=0,jl=0;
		for(int i=0;i<52;i++){
			bool flag=1;
			for(int k=1;k<=n;k++)if(!pa[k][i])flag=0;
			if(flag){
				int tmp=dp(i,0);
				if(tmp>ans){
					ans=tmp;
					jl=i;
				}
			}
		}
		cout<<ans<<'\n';
		if(ans)tp(jl,0);
		cout<<'\n';
	}
	return 0;
}