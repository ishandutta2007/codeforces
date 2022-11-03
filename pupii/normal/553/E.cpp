#include<bits/stdc++.h>
typedef long long ll;
#define NN 65536
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
const double pi=acos(-1);
struct cp{
	double real,imag;
	cp operator+(const cp&x)const{return(cp){real+x.real,imag+x.imag};}
	void operator+=(const cp&x){real+=x.real,imag+=x.imag;}
	cp operator-(const cp&x)const{return(cp){real-x.real,imag-x.imag};}
	cp operator*(const cp&x)const{return(cp){real*x.real-imag*x.imag,imag*x.real+real*x.imag};}
	void operator=(const int&x){real=x,imag=0;}
	cp(double a=0,double b=0){real=a,imag=b;}
};
cp conj(cp x){x.imag*=-1;return x;}
int n,m,t,x;
cp w[65539],iw[65539],A[65539],B[65539];
int fir[51],dis[110],nxt[110],id,px[111],py[111],pc[111],dp[51];
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
double pw[111][40010];
double f[51][40010],g[101][20010];
int rev[65569];
void fft(cp*A,int N,cp*omg){
	for(int i=0;i<N;++i)if(rev[i]>i)std::swap(A[i],A[rev[i]]);
	for(int o=1;o<N;o<<=1)
		for(cp*p=A;p!=A+N;p+=o<<1)
			for(int i=0;i<o;++i){
				cp t=p[i+o]*omg[NN/(o<<1)*i];
				p[i+o]=p[i]-t;p[i]+=t;
			}
}
void update(int l1,int r1,int l2,int r2){
	int lim=r2-l1+3,N=1,lg=0;
	while(N<lim)N<<=1,++lg;
	for(int i=0;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
	for(int _=1,y;_<=m;++_){
		y=py[_];
		for(int i=0;i<N;++i)A[i]=B[i]={0,0};
		for(int i=r2,j=0;i>=l2;--i,++j)A[j]={f[y][i],0};
		for(int i=0;i<=std::min(t,r2-l1+1);++i)B[i]={pw[_][i],0};
		fft(A,N,w),fft(B,N,w);
		for(int i=0;i<N;++i)A[i]=A[i]*B[i];
		fft(A,N,iw);
		for(int i=r1,j=r2-l2+1;i>=l1;--i,++j)g[_][i]+=A[j].real/N;
	}
}
void solve(int l,int r){
	if(l==r){
		for(int _=1,x;_<=m;++_)x=px[_],f[x][l]=std::min(f[x][l],g[_][l]+pc[_]);
		return;
	}
	int mid=(l+r)>>1;
	solve(mid+1,r);
	update(l,mid,mid+1,r);
	solve(l,mid);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),t=gi(),x=gi();
	for(int i=0;i<NN;++i)w[i]={cos(2*i*pi/NN),sin(2*i*pi/NN)};
	for(int i=0;i<NN;++i)iw[i]=conj(w[i]);
	int u,v;
	for(int i=1;i<=m;++i){
		px[i]=u=gi(),py[i]=v=gi(),link(v,u);pc[i]=gi();
		for(int j=1;j<=t;++j)pw[i][j]=gi()*1e-5;
	}
	for(int i=1;i<=n;++i)dp[i]=1e9;
	dp[n]=0;
	for(int _=1;_<=n;++_){
		static bool fixed[51];
		int x=0;
		for(int i=1;i<=n;++i)if(!fixed[i]&&(!x||dp[x]>dp[i]))x=i;
		for(int i=fir[x];i;i=nxt[i])dp[dis[i]]=std::min(dp[dis[i]],dp[x]+pc[i]);
		fixed[x]=1;
	}
	for(int i=1;i<n;++i){
		for(int j=0;j<=t;++j)f[i][j]=1e233;
		for(int j=t+1;j<=t+t;++j)f[i][j]=dp[i]+x;
	}
	for(int j=0;j<=t+t;++j)f[n][j]=j>t?x:0;
	update(1,t,t+1,t+t);
	solve(0,t);
	printf("%.10lf\n",f[1][0]);
	return 0;
}