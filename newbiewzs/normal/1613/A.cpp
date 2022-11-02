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
const int N=10;
int T,n,m,x,y,ta,tb;
int sa[N],sb[N],ha,hb;
int main(){
	#ifdef newbiewzs
	#else
	#endif
	T=read();
	while(T--){
		n=read();x=read();
		m=read();y=read();
		int tmp=n;
		ha=hb=ta=tb=0;
		while(tmp){
			ta++;
			sa[++ha]=tmp%10;
			tmp/=10;
		}
		tmp=m;
		while(tmp){
			tb++;
			sb[++hb]=tmp%10;
			tmp/=10;
		}
		if(ta+x<tb+y){
			cout<<"<"<<'\n';
		}
		else if(ta+x>tb+y){
			cout<<">"<<'\n';
		}
		else{
			reverse(sa+1,sa+ha+1);
			reverse(sb+1,sb+hb+1);
			int flag=0;
			for(int i=1;i<=min(ha,hb);i++){
				if(sa[i]>sb[i]){
					flag=1;
					break;
				}
				if(sa[i]<sb[i]){
					flag=2;
					break;
				}
			}
			if(flag==1)puts(">");
			else if(flag==2)puts("<");
			else{
				if(ha<hb){
					
					for(int i=ha+1;i<=hb;i++){
						if(sb[i]!=0)flag=1;
					}
					if(flag)puts("<");
					else puts("=");
				}
				else if(ha>hb){
					for(int i=hb+1;i<=ha;i++){
						if(sa[i]!=0)flag=1;
					}
					if(flag)puts(">");
					else puts("=");
				}
				else {
					puts("=");
				}	
			}
			
		}
	}
	return 0;
}