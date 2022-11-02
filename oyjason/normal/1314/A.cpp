#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
using namespace std;
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	inline int read(){
		int nm=0; bool fh=1; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 400010
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
int n,_a[M],_t[M],a[M],t[M],od[M],cur;
LL ans,sum;
inline bool cmp(int x,int y){return _a[x]<_a[y];}
priority_queue<int>Q;
int now=-1;
int main(){

	n=read();
	for(int i=1;i<=n;i++) _a[i]=read(),od[i]=i;
	for(int i=1;i<=n;i++) _t[i]=read();
	sort(od+1,od+n+1,cmp);
	for(int i=1;i<=n;i++) a[i]=_a[od[i]],t[i]=_t[od[i]];//debug(a[i])sp,debug(t[i])el;

	for(int i=1;i<=n;){
		if(Q.empty()) now=a[i];
		while(now==a[i]&&i<=n){
			Q.push(t[i]),sum+=t[i],i++;
		}
		while(!Q.empty()&&(i>n||now<a[i])) sum-=Q.top(),now++,ans+=sum,Q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}