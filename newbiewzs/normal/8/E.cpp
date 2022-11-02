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
#include<cmath>
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
#define mem1(x) memset(x,-1,sizeof(x))
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
#define int long long
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
const int N=51;
int n,m,s,a[N],f[30][2][2];
int dfs(int u,int x,int y){
	if(~f[u][x][y])return f[u][x][y];
	if(u==s){
		int summ=0;
		if(n&1){
			if(a[u]!=-1){
				if(x)summ=1;
				else if(y){
					if(a[u]==0)summ=1;
				}
				else summ=1;
			}
			else{
				if(x)summ=2;
				else if(y)summ=1;
				else summ=2;
			}
			
		}
		else{
			for(int i=0;i<=1;i++){
				if(~a[u] && a[u]!=i)continue;
				for(int k=0;k<=1;k++){
					if(~a[n-u+1] && a[n-u+1]!=k)continue;
					if(x){
						if(i==k || i<k)summ++;
					}
					else if(y){
						if(i!=k || i==0)summ++;
					}
					else summ++;
				}
			}
		}
		return summ;
	}
	int tmp=0;
	if(u==1){
		if(a[n]!=-1){
			if(a[1]!=a[n])tmp=dfs(u+1,0,1);
			else tmp=dfs(u+1,1,0);
		}
		else tmp=dfs(u+1,1,0)+dfs(u+1,0,1);
	}
	else{
		for(int i=0;i<=1;i++){
			if(~a[u] && a[u]!=i)continue;
			for(int k=0;k<=1;k++){
				if(~a[n-u+1] && a[n-u+1]!=k)continue;
				if(x){
					if(i==k)tmp+=dfs(u+1,x,y);
					else if(i<k)tmp+=dfs(u+1,0,0);
				}
				else if(y){
					if(i!=k)tmp+=dfs(u+1,x,y);
					else if(i==0)tmp+=dfs(u+1,0,0);
				}
				else {
					tmp+=dfs(u+1,0,0);
				}
			}
		}
	}
	f[u][x][y]=tmp;
	return tmp;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read()+1;s=(n+1)/2;
	mem1(a);a[1]=0;mem1(f);
	for(int i=2;i<=n;i++){
		mem1(f);
		a[i]=0;
		int tmp=dfs(1,1,1);
		if(tmp<m){
			m-=tmp;
			a[i]=1;
		}
	}
	if(m>1){
		puts("-1");
		return 0;
	}
	string ta,tb,tc;
	for(int i=1;i<=n;i++){
		if(a[i]==0)ta+="0";
		else ta+="1";
	}
	for(int i=n;i>=1;i--){
		if(a[i]==0)tb+="0",tc+="1";
		else tb+="1",tc+="0";
	}
	if(ta>tb || ta>tc){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}