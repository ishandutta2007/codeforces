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
int n,m,x,y,vx,vy,fa=1,fb=1,ax,ay;
int gcd(int xx,int yy){
	if(!xx)return yy;
	return gcd(yy%xx,xx);
}
void exgcd(int xx,int yy,int &a,int &b){
	if(!xx){
		if(yy<0)b=-1;
		else b=1;
		a=0;return ;
	}
	exgcd(yy%xx,xx,a,b);
	int tx=a,ty=b;
	a=ty-(yy/xx)*tx;
	b=tx;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();x=read();y=read();vx=read();vy=read();
	if(vx==0 || vy==0){
		if(vx && (y==0 || y==m)){
			if(y==0){
				if(vx==1)cout<<n<<" "<<0;
				else cout<<0<<" "<<0;
			}
			if(y==m){
				if(vx==1)cout<<n<<" "<<m;
				else cout<<0<<" "<<m;
			}
		}
		else if(vy && (x==0 || x==n)){
			if(x==0){
				if(vy==1)cout<<x<<" "<<m;
				else cout<<x<<" "<<0;
			}
			if(x==n){
				if(vy==1)cout<<x<<" "<<m;
				else cout<<x<<" "<<0;
			}
		}
		else {
			puts("-1");
		}
		return 0;
	}
	if(vx==-1)fa=0,x=n-x;
	if(vy==-1)fb=0,y=m-y;
	int D=x-y;
	int G=gcd(n,m);
	if(D%G){
		puts("-1");return 0;
	}
	
	exgcd(n,-m,ax,ay);
	int C=D/G;
	ax*=C;ay*=C;
	
	int A=(m/G);
	ax=(ax%A+A)%A;
	if(!ax)ax+=A;
//	ax=((ax+A-1)%A+A)%A+1;
	ay=(ax*n-(x-y))/m;
	
	if(!(ax&1))fa^=1;
	if(!(ay&1))fb^=1;
	
	cout<<(fa?n:0)<<" "<<(fb?m:0);
	return 0;
}