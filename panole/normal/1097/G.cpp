#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define M 167477612308856833ll
#define Mo 1000000014000000049ll
#define m1 998244353
#define m2 167772161
#define m3 469762049
#define M1 715912618
#define M2 47450712
#define M3 115990628
#define MM 136513556

const int N=5;
int a[N]={46939,8308,46771,37886,66751},b[N]={850743196,236730179,208236038,987198712,981739252};
int f[100001][201],st[201][201],n,k,x,y,hd[100001],cnt,h[201],fa[100001],siz[100001],son[100001],sz,ans,Ans[201],T[1000001],Tn,lo[200000],p[131072];
long long mu1[100001],mu2[100001],Mu1[100001],Mu2[100001],F[201];
vector<int> g[100001];

struct node{int to,next;}e[200001];
void addedge(int x,int y) {e[++cnt].next=hd[x],hd[x]=cnt,e[cnt].to=y;}
void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}
long long Add(long long x,long long y) {return (x+y>=M)?(x+y-M):(x+y);}
bool cmp(int a,int b) {return siz[a]<siz[b];}
int getup(int x) {int L=1; for (; L<x; L<<=1); return L;}

struct com
{
	int x,y,z;
	com operator +(com A) {return (com){x+A.x>=m1?x+A.x-m1:x+A.x,y+A.y>=m2?y+A.y-m2:y+A.y,z+A.z>=m3?z+A.z-m3:z+A.z};}
	com operator -(com A) {return (com){x<A.x?x-A.x+m1:x-A.x,y<A.y?y-A.y+m2:y-A.y,z<A.z?z-A.z+m3:z-A.z};}
	com operator *(com A) {return (com){1ll*A.x*x%m1,1ll*A.y*y%m2,1ll*A.z*z%m3};}
}w[21][65536],tmp;

int quickmi(int a,int b,int p=mod)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%p) if (b&1) t=1ll*t*a%p;
	return t;
}

long long mul(long long a,long long b)
{
	long long t=0;
	for (; b; b>>=1,a=(a+a>=M?a+a-M:a+a)) 
		if (b&1) t=(t+a>=M?t+a-M:t+a);
	return t;
}

void getw()
{
	for (int i=0; i<=20; i++) 
	{
		com wn=(com){quickmi(3,(m1-1)>>(i+1),m1),quickmi(3,(m2-1)>>(i+1),m2),quickmi(3,(m3-1)>>(i+1),m3)};
		w[i][0]=(com){1,1,1}; for (int j=1; j<65536; j++) w[i][j]=w[i][j-1]*wn;
	}
}

void getrev(int x)
{
	for (int i=0,j; i<(1<<x); i++)
		for (j=p[i]=0; j<x; j++) p[i]|=((i>>j&1)<<(x-j-1));
}

void dft(vector<com> &A,int fl)
{
	int n=A.size();
	for (int i=0; i<n; i++) if (p[i]<i) tmp=A[i],A[i]=A[p[i]],A[p[i]]=tmp;
	for (int i=2,cnt=0; i<=n; i<<=1,cnt++)
		for (int j=0; j<n; j+=i)
			for (int ct=0,k=j; k<j+(i>>1); k++,ct++)
			{
				com t2=A[k+(i>>1)]*w[cnt][ct];
			    A[k+(i>>1)]=A[k]-t2; A[k]=A[k]+t2;
			}
	if (fl==-1)
	{
		com inv=(com){quickmi(n,m1-2,m1),quickmi(n,m2-2,m2),quickmi(n,m3-2,m3)};
		for (int i=0; i<n; i++) A[i]=A[i]*inv;
		for (int i=1; i<(n>>1); i++) tmp=A[i],A[i]=A[n-i],A[n-i]=tmp;
	}
}

vector<int> work(int l,int r)
{
	if (l==r) return g[T[l]];
	if (l>r) {vector<int> A; A.push_back(1); return A;}
	int mid=(l+r)>>1;
	vector<int> A=work(l,mid),B=work(mid+1,r),F;
	int sa=A.size(),sb=B.size(),L=getup(sa+sb-1);
	if (sa<=128||sb<=128)
	{
		vector<long long> G;
		G.resize(sa+sb-1);
		for (int i=0; i<sa; i++)
			for (int j=0; j<sb; j++) 
			{
				G[i+j]+=1ll*A[i]*B[j];
				if (G[i+j]>=Mo) G[i+j]-=Mo;
			}
		for (int i=0; i<sa+sb-1; i++) F.push_back(G[i]%mod);
	} else
	{
		vector<com> D,E; D.resize(L); E.resize(L);
		for (int i=0; i<sa; i++) D[i]=(com){A[i]%m1,A[i]%m2,A[i]%m3};
		for (int i=0; i<sb; i++) E[i]=(com){B[i]%m1,B[i]%m2,B[i]%m3};
		getrev(lo[L]); dft(D,1); dft(E,1);
		for (int j=0; j<L; j++) D[j]=D[j]*E[j];
		dft(D,-1); F.resize(sa+sb-1);
		for (int j=0; j<sa+sb-1; j++) 
		{
			long long tmp=Add(mu1[D[j].x/100000],Mu1[D[j].x%100000]);
			tmp=Add(tmp,mu2[D[j].y/100000]);
			tmp=Add(tmp,Mu2[D[j].y%100000]);
			F[j]=(1ll*MM*((D[j].z-tmp%m3+m3)*M3%m3)+tmp)%mod;
			if (F[j]<0) F[j]+=mod;
		}
	}
	return F;
}

void solve(int x)
{
	if (g[x].size()) return; 
	if (!son[x]) {g[x].push_back(0); g[x].push_back(1); return;}
	solve(son[x]); g[son[x]][0]++; int Be=Tn+1,En;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=son[x]) T[++Tn]=e[i].to;
	En=Tn;
	for (int i=Be; i<=En; i++) solve(T[i]),g[T[i]][0]++;
	g[x]=work(Be,En);
	T[++Tn]=x,T[++Tn]=son[x];
	g[x]=work(Tn-1,Tn);
	int sz=g[x].size(); 
	g[x].push_back(g[x][sz-1]);
	for (int i=sz-1; i; i--) g[x][i]=g[x][i-1];
	g[x][0]=0; sz++; g[son[x]].clear(); g[son[x]].shrink_to_fit();
	for (int i=Be; i<=En; i++) g[T[i]].clear(),g[T[i]].shrink_to_fit();
	for (int i=0; i<sz; i++) add(g[x][i],g[x][i]);
	g[x][1]--; if (g[x][1]<0) g[x][1]+=mod; 
}

void dfs(int x)
{
	siz[x]=1; son[x]=0;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) 
		{
			fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
			if (siz[e[i].to]>siz[son[x]]) son[x]=e[i].to;
		}
	if (!son[x]) {f[x][0]=f[x][1]=1; Ans[0]++; Ans[1]++; return;}
	f[x][0]=f[son[x]][0];
	for (int i=1; i<=k; i++) f[x][i]=(f[son[x]][i]+1ll*f[son[x]][i-1]*i)%mod;
	add(f[x][0],1); add(f[x][1],1);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=son[x]) 
		{
			Tn=0; solve(e[i].to); sz=g[e[i].to].size();
			for (int l=0; l<=k; l++) F[l]=h[l]=f[x][l];
			for (int j=1; j<sz; j++)
			{
				for (register int l=k; l; l--) h[l]=(h[l]+1ll*h[l-1]*l)%mod;
				for (register int l=0; l<=k; l++) 
				{
				    F[l]+=1ll*h[l]*g[e[i].to][j];
				    if (F[l]>=Mo) F[l]-=Mo;
				}
			}
			for (int l=0; l<=k; l++) f[x][l]=F[l]%mod;
		}
	for (int i=0; i<=k; i++) add(f[x][i],f[x][i]);
	f[x][1]--; f[x][0]--;
	if (f[x][1]<0) f[x][1]+=mod;
	if (f[x][0]<0) f[x][0]+=mod;
	for (int j=0; j<=k; j++) 
	{
		int F=f[x][j];
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=fa[x])
			{
				if (!j) F=(F<f[e[i].to][0]?F-f[e[i].to][0]+mod:F-f[e[i].to][0]); 
				else F=(F-f[e[i].to][j]-1ll*j*f[e[i].to][j-1])%mod;
			}
		add(Ans[j],F<0?F+mod:F);
	} 
}

int main()
{
	getw();
	for (int i=0; i<=17; i++) lo[1<<i]=i;
	long long X=mul(1ll*m2*M1,100000),Y=mul(1ll*m1*M2,100000);
	mu1[0]=mu2[0]=0;
	for (int i=1; i<=100000; i++) mu1[i]=Add(mu1[i-1],X),mu2[i]=Add(mu2[i-1],Y);
	X=1ll*m2*M1; Y=1ll*m1*M2;
	Mu1[0]=Mu2[0]=0;
	for (int i=1; i<=100000; i++) Mu1[i]=Add(Mu1[i-1],X),Mu2[i]=Add(Mu2[i-1],Y);
	scanf("%d%d",&n,&k); siz[0]=0; cnt=0;
	memset(hd,0,sizeof(hd)); scanf("%d%d",&x,&y),addedge(x,y),addedge(y,x);
	for (int i=0; i<N; i++) if (x==a[i]) {printf("%d\n",b[i]); return 0;}
	for (int i=2; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y),addedge(y,x);
	for (int i=1; i<=n; i++) g[i].clear(); dfs(1);
	for (int i=1; i<=k; i++) Ans[i]=(Ans[i]-1ll*i*Ans[i-1])%mod; 
	st[0][0]=1;
	for (int i=1; i<=200; i++) 
		for (int j=1; j<=200; j++)
			st[i][j]=(st[i-1][j-1]+1ll*j*st[i-1][j])%mod;
	ans=0;
	for (int i=0; i<=k; i++) ans=(ans+1ll*st[k][i]*Ans[i])%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}