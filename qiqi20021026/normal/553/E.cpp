#include<bits/stdc++.h>

using namespace std;

typedef double LD;
#define N 80000

const LD pi=(LD)3.1415926535897932;
int n,m,t,p,rev[N],a[105],b[105],c[105],g[105][105];
LD f[55][N],F[105][N],d[105][N],sd[105][N];
struct C{
	LD x,y;
	inline C():x(0),y(0){}
	inline C(LD x,LD y):x(x),y(y){}
	C operator * (const LD a) const{return C(x*a,y*a);}
	C operator / (const LD a) const{return C(x/a,y/a);}
	C operator + (const C a) const{return C(x+a.x,y+a.y);}
	C operator - (const C a) const{return C(x-a.x,y-a.y);}
	C operator * (const C a) const{return C(x*a.x-y*a.y,x*a.y+y*a.x);}
}A[N],B[N],w[20][1<<18];

int getint(){
	char ch; int sum=0;
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) sum=sum*10+ch-'0';
	return sum;
}

void fft_init(int &n){
	int k; for (k=0;1<<k<=n;k++);
	n=1<<k; rev[0]=0;
	for (int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
}

void fft(C a[],int n){
	for (int i=0;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int i=0;1<<i<n;i++){
		int t=1<<i;
		for (int j=0;j<n;j+=t<<1){
			C *aa=a+j,*bb=a+j+t;
			for (int k=0;k<t;k++){
				C t=w[i][k]*bb[k];
				bb[k]=aa[k]-t;
				aa[k]=aa[k]+t;
			}
		}
	}
}

void cdq(int l,int r){
	if (l==r){
		for (int i=1;i<=n;++i) f[i][l]=1e9;
		f[n][l]=0;
		for (int i=1;i<=m;++i){
			int x=a[i],y=b[i];
			f[x][l]=min(f[x][l],F[i][l]+c[i]+sd[i][l+1]*(g[y][n]+p));
		}
		return;
	}
	int mid=(l+r)>>1;
	cdq(l,mid);
	for (int i=1;i<=m;++i){
		int y=b[i];
		for (int j=l;j<=mid;++j) A[j-l]=C(f[y][j],0);
		for (int j=1;j<=r-l+1;++j) B[j]=C(d[i][j],0);
		int len=mid-l+1+r-l+1; fft_init(len); 
		fft(A,len); fft(B,len);
		for (int j=0;j<len;++j) A[j]=A[j]*B[j];
		fft(A,len); reverse(A+1,A+len);
		for (int j=0;j<len;++j) A[j]=A[j]/len;
		for (int j=mid+1;j<=r;++j) F[i][j]+=A[j-l].x;
		for (int j=0;j<len;++j) A[j]=B[j]=C();
	}
	cdq(mid+1,r);
}

int main(){
	scanf("%d%d%d%d",&n,&m,&t,&p);
	memset(g,0x3f,sizeof g);
	w[0][0]=C(1,0);
	for (int i=1;i<=18;++i){
		w[i][0]=C(1,0); w[i][1]=C(cos(pi/(1<<i)),sin(pi/(1<<i)));
		for (int j=2;j<1<<i;++j) w[i][j]=w[i][1]*w[i][j-1];
	}
	for (int i=1;i<=n;++i) g[i][i]=0;
	for (int i=1;i<=m;++i){
		a[i]=getint(); b[i]=getint(); c[i]=getint();
		g[a[i]][b[i]]=min(g[a[i]][b[i]],c[i]);
		for (int j=1;j<=t;++j) d[i][j]=getint()/100000.0;
		for (int j=t;~j;--j) sd[i][j]=d[i][j]+sd[i][j+1];
	}
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	cdq(0,t);
	LD ans=1e9; for (int i=0;i<=t;++i) ans=min(ans,f[1][i]);
	printf("%.10lf\n",ans);
	
	return 0;
}