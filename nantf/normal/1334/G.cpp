#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod[2]={998244353,1004535809};
const double pi=3.14159265358979;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,a[maxn],b[maxn],c[maxn],p[26],lim,l,rev[maxn];
ll pre[maxn];
char s[maxn],t[maxn];
double ans[maxn];
struct comp{
	double x,y;
	comp(double xx=0,double yy=0):x(xx),y(yy){}
	comp operator+(const comp &c)const{return comp(x+c.x,y+c.y);}
	comp operator-(const comp &c)const{return comp(x-c.x,y-c.y);}
	comp operator*(const comp &c)const{return comp(x*c.x-y*c.y,x*c.y+y*c.x);}
}A[maxn],B[maxn];
void init(int upr){
	for(lim=1,l=0;lim<upr;lim<<=1,l++);
	FOR(i,0,lim-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
}
void FFT(comp *A,int tp){
	FOR(i,0,lim-1) if(i<rev[i]) swap(A[i],A[rev[i]]);
	for(int i=1;i<lim;i<<=1){
		comp Wn(cos(pi/i),tp*sin(pi/i));
		for(int j=0;j<lim;j+=i<<1){
			comp w(1,0);
			FOR(k,0,i-1){
				comp x=A[j+k],y=A[i+j+k]*w;
				A[j+k]=x+y;A[i+j+k]=x-y;
				w=w*Wn;
			}
		}
	}
	if(tp==-1) FOR(i,0,lim-1) A[i]=comp(A[i].x/lim,0);
}
void work(){
	FFT(A,1);FFT(B,1);
	FOR(i,0,lim-1) A[i]=A[i]*B[i];
	FFT(A,-1);
	FOR(i,0,m-n) ans[i]+=A[n-1+i].x;
	FOR(i,0,lim-1) A[i]=B[i]=0;
}
int main(){
	FOR(i,0,25) p[i]=read();
	scanf("%s%s",s,t);
	n=strlen(s);m=strlen(t);
	FOR(i,0,n-1) a[i]=s[n-1-i]-'a',b[i]=p[a[i]]-1;
	FOR(i,0,m-1) c[i]=t[i]-'a';
	init(n+m+1);
	pre[0]=c[0]*c[0]*c[0]*c[0];
	FOR(i,1,m-1) pre[i]=pre[i-1]+c[i]*c[i]*c[i]*c[i];
	ans[0]=pre[n-1];
	FOR(i,1,m-n) ans[i]=pre[i+n-1]-pre[i-1];
	ll s=0;
	FOR(i,0,n-1) s=s+a[i]*a[i]*b[i]*b[i];
	FOR(i,0,m-n) ans[i]+=s;
	FOR(i,0,n-1) A[i]=-2*a[i]*b[i]*b[i]-2*a[i]*a[i]*b[i];
	FOR(i,0,m-1) B[i]=c[i];
	work();
	FOR(i,0,n-1) A[i]=a[i]*a[i]+4*a[i]*b[i]+b[i]*b[i];
	FOR(i,0,m-1) B[i]=c[i]*c[i];
	work();
	FOR(i,0,n-1) A[i]=-2*a[i]-2*b[i];
	FOR(i,0,m-1) B[i]=c[i]*c[i]*c[i];
	work();
	FOR(i,0,m-n) printf(fabs(ans[i])<=0.5?"1":"0");
}