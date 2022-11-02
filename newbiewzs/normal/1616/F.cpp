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
const int N=65;
const int M=258;
const int mod=3;
int T,n,m,top,x[M],y[M],z[M];
int a[4200][M];
int g[N][N],ans[M];
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
int solve(){
	int pre=1;
	for(int i=1;i<=m;i++){
		int pos=-1;
		for(int k=pre;k<=top;k++){
			if(a[k][i]!=0){
				pos=k;break;
			}
		}
		if(pos==-1)continue;
		if(pos!=pre)swap(a[pos],a[pre]);
		if(a[pre][i]==2){
			for(int k=1;k<=m+1;k++)a[pre][k]=add(a[pre][k],a[pre][k]);
		}
		for(int k=1;k<=top;k++){
			if(k==pre)continue;
			if(!a[k][i])continue;
			int tmp=a[k][i];
			for(int j=1;j<=m+1;j++){
				a[k][j]=(a[k][j]-a[pre][j]*tmp+6)%mod;
			}
		}
		pre++;
	}
	for(int i=1;i<=top;i++){
		int jl=0;
		for(int k=1;k<=m;k++){
			if(a[i][k]!=0){
				jl=k;
				break;
			}
		}
		if(!jl && a[i][m+1]){
			return -1;
		}
		ans[jl]=a[i][m+1];
	}
	return 1;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();memset(a,0,sizeof(a));memset(g,-1,sizeof(g));top=0;
		for(int i=1;i<=m;i++){
			x[i]=read();y[i]=read();z[i]=read();
			if(z[i]!=-1){
				z[i]%=3;
				top++;
				a[top][i]=1;
				a[top][m+1]=z[i];
			}
			g[x[i]][y[i]]=g[y[i]][x[i]]=i;
		}
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				for(int j=k+1;j<=n;j++){
					if(g[i][k]==-1 || g[k][j]==-1 || g[j][i]==-1)continue;
					top++;
					a[top][g[i][k]]=a[top][g[k][j]]=a[top][g[j][i]]=1;
					a[top][m+1]=0;
				}
			}
		}
		if(solve()==-1){
			puts("-1");
		}
		else{
			for(int i=1;i<=n;i++){
				for(int k=1;k<=n;k++){
					for(int j=1;j<=n;j++){
						if(g[i][k]==-1 || g[k][j]==-1 || g[j][i]==-1)continue;
						bool flag=0;
						if((ans[g[i][k]]+ans[g[i][j]]+ans[g[k][j]])%3==0)flag=1;
						if(!flag){
							puts("NONONONONO");
							return 0;
						}
					}
				}
			}
			for(int i=1;i<=m;i++){
				if(ans[i]==0)ans[i]=3;
				cout<<ans[i]<<" ";
			}
			cout<<'\n';
		}
		memset(ans,0,sizeof(ans));
	}
	return 0;
}