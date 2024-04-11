#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod1=998244353,mod2=998244352;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct matrix{
	int a[111][111];
	matrix(){MEM(a,0);}
	matrix operator*(const matrix &t)const{
		matrix ans;
		FOR(i,0,99) FOR(k,0,99) FOR(j,0,99) ans.a[i][j]=(ans.a[i][j]+1ll*a[i][k]*t.a[k][j])%mod2;
		return ans;
	}
}beg,fac,ans;
int k,n,m,b[111];
matrix qpow(matrix a,int b){
	matrix ans;
	FOR(i,0,99) ans.a[i][i]=1;
	for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
	return ans;
}
int qpow(int a,ll b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod1) if(b&1) ans=1ll*ans*a%mod1;
	return ans;
}
int BSGS(int a,int b,int p){
	a%=p;b%=p;
	map<int,int> mp;
	int sq=ceil(sqrt(p));
	for(int pr=b,i=0;i<=sq;i++,pr=1ll*pr*a%p) mp[pr]=i;
	int fac=qpow(a,sq);
	for(int pr=fac,i=1;i<=sq;i++,pr=1ll*pr*fac%p){
		if(mp.count(pr)) return i*sq-mp[pr];
	}
	return -1;
}
int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return a;}
	int d=exgcd(b,a%b,y,x);y-=a/b*x;return d;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int inv(int a,int p,int &d){
	int x,y;d=exgcd(a,p,x,y);
	return (x+p)%p;
}
int main(){
	k=read();
	FOR(i,1,k) b[i]=read();
	n=read();m=read();
	FOR(i,0,k-2) beg.a[i][0]=0;
	beg.a[k-1][0]=1;
	FOR(i,0,k-2) fac.a[i][i+1]=1;
	FOR(i,0,k-1) fac.a[k-1][i]=b[k-i]%mod2;
	ans=qpow(fac,n-k)*beg;
	int tim=ans.a[k-1][0];
	int r=BSGS(3,m,mod1);
	if(r==-1) return puts("-1"),0;
	int g,tinv=inv(tim,mod2,g);
	if(r%g) return puts("-1"),0;
	r=1ll*r/g*tinv%mod2;
	printf("%d\n",qpow(3,r));
}