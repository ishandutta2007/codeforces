#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod1=1000000007,mod2=1000000006;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
ll n;
int f1,f2,f3,c,x,y,z,w;
struct matrix{
	int a[5][5];
	matrix(){MEM(a,0);}
	matrix operator*(const matrix &t)const{
		matrix ans;
		FOR(i,0,4) FOR(k,0,4) FOR(j,0,4) ans.a[i][j]=(ans.a[i][j]+1ll*a[i][k]*t.a[k][j])%mod2;
		return ans;
	}
}beg,fac,ans;
matrix qpow(matrix a,ll b){
	matrix ans;
	FOR(i,0,4) ans.a[i][i]=1;
	for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
	return ans;
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod1) if(b&1) ans=1ll*ans*a%mod1;
	return ans;
}
int main(){
	n=read();f1=read();f2=read();f3=read();c=read();
	fac.a[0][0]=fac.a[0][1]=fac.a[0][2]=fac.a[1][0]=fac.a[2][1]=1;
	beg.a[2][0]=1;
	ans=qpow(fac,n-3)*beg;
	x=ans.a[0][0];
	beg=matrix();
	beg.a[1][0]=1;
	ans=qpow(fac,n-3)*beg;
	y=ans.a[0][0];
	beg=matrix();
	beg.a[0][0]=1;
	ans=qpow(fac,n-3)*beg;
	z=ans.a[0][0];
	beg=matrix();fac=matrix();
	beg.a[3][0]=3;beg.a[4][0]=1;
	fac.a[0][0]=fac.a[0][1]=fac.a[0][2]=fac.a[1][0]=fac.a[2][1]=fac.a[3][3]=fac.a[3][4]=fac.a[4][4]=1;
	fac.a[0][3]=2;fac.a[0][4]=mod2-4;
	ans=qpow(fac,n-3)*beg;
	w=ans.a[0][0];
	printf("%lld\n",1ll*qpow(f1,x)*qpow(f2,y)%mod1*qpow(f3,z)%mod1*qpow(c,w)%mod1);
}