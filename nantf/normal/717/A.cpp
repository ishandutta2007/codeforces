#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=222,mod=1000000007,inv2=500000004,inv5=400000003;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int k,fac[maxn],invfac[maxn],ans,S[maxn][maxn],C[maxn][maxn];
ll l,r;
inline int add(int x,int y){return x+y<mod?x+y:x+y-mod;}
inline int sub(int x,int y){return x<y?x-y+mod:x-y;}
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int qpow(int a,ll b){
	int ans=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) ans=mul(ans,a);
	return ans;
}
struct comp{
	int x,y;
	comp(const int xx=0,const int yy=0):x(xx),y(yy){}
	inline comp operator+(const comp &c)const{return comp(add(x,c.x),add(y,c.y));}
	inline comp operator-(const comp &c)const{return comp(sub(x,c.x),sub(y,c.y));}
	inline comp operator*(const comp &c)const{return comp(add(mul(x,c.x),mul(5,mul(y,c.y))),add(mul(x,c.y),mul(y,c.x)));}
	inline comp inv()const{
		comp ans(x,y?mod-y:0);
		int dn=qpow(sub(mul(x,x),mul(5,mul(y,y))),mod-2);
		return ans*dn;
	}
	inline comp operator/(const comp &c)const{return *this*c.inv();}
	inline bool operator==(const comp &c)const{return x==c.x && y==c.y;}
}a(0,inv5),b(0,mod-inv5),x(inv2,inv2),y(inv2,mod-inv2);
inline comp cqpow(comp a,ll b){
	comp ans(1,0);
	for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
	return ans;
}
comp calc(comp x,ll l,ll r){
	if(x==1) return (r-l+1)%mod;
	return (cqpow(x,r+1)-cqpow(x,l))/(x-1);
}
int main(){
	k=read();l=read();r=read();
	FOR(i,0,k) C[i][0]=C[i][i]=1;
	FOR(i,1,k) FOR(j,1,i-1) C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	S[1][1]=1;
	FOR(i,2,k) FOR(j,1,i) S[i][j]=add(mul(i-1,S[i-1][j]),S[i-1][j-1]);
	fac[0]=1;
	FOR(i,1,k) fac[i]=mul(fac[i-1],i);
	invfac[k]=qpow(fac[k],mod-2);
	FOR(i,0,k){
		int s=0;
		FOR(j,0,i){
			comp tmp1=cqpow(a,j)*cqpow(b,i-j),tmp2=cqpow(x,j)*cqpow(y,i-j);
			s=add(s,mul(C[i][j],(tmp1*calc(tmp2,l+2,r+2)).x));
		}
		s=mul(s,S[k][i]);
		if((k-i)&1) ans=sub(ans,s);
		else ans=add(ans,s);
	}
	printf("%d\n",mul(ans,invfac[k]));
}