#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

#define poly vector<int>
#define cpoly vector<Complex>
const double pi=acos(-1.0);
struct Complex{double x,y;};
Complex operator +(Complex a,Complex b){return (Complex){a.x+b.x,a.y+b.y};}
Complex operator -(Complex a,Complex b){return (Complex){a.x-b.x,a.y-b.y};}
Complex operator *(Complex a,Complex b){return (Complex){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
poly rev;
int lim,l;
void FFT(cpoly &a,int type)
{
	for (int i=0;i<lim;i++) if (rev[i]<i) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<lim;mid*=2)
	{
		Complex Wn=(Complex){cos(pi/mid),type*sin(pi/mid)};
		for (int len=mid*2,k=0;k<lim;k+=len)
		{
			Complex w=(Complex){1,0};
			for (int i=k;i<k+mid;i++,w=w*Wn)
			{
				Complex x=a[i],y=w*a[i+mid];
				a[i]=x+y;
				a[i+mid]=x-y;
			}
		}
	}
	if (type<0) for (auto &i:a) i.x/=lim;
}
int a[N],b[N];

signed main()
{
	int n=read(),m=read(),Q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	lim=1,l=0;
	while (lim<=2e5) lim*=2,l++;
	rev.resize(lim);
	for (int i=1;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	cpoly A(lim),B(lim),mxA(lim),mxB(lim),mnA(lim),mnB(lim),res1(lim+1),res2(lim+1);
	for (int i=1;i<=n;i++) A[a[i]].x+=1;
	for (int i=1;i<=m;i++) B[b[i]].x+=1;
	for (int i=1;i<n;i++) mxA[max(a[i],a[i+1])].x+=1;
	for (int i=1;i<m;i++) mxB[max(b[i],b[i+1])].x+=1;
	for (int i=1;i<n;i++) mnA[min(a[i],a[i+1])].x+=1;
	for (int i=1;i<m;i++) mnB[min(b[i],b[i+1])].x+=1;
	FFT(A,1),FFT(B,1),FFT(mxA,1),FFT(mxB,1),FFT(mnA,1),FFT(mnB,1);
	for (int i=0;i<lim;i++) res1[i]=A[i]*B[i]-A[i]*mnB[i]-mnA[i]*B[i]+mnA[i]*mnB[i];
	for (int i=0;i<lim;i++) res2[i]=A[i]*B[i]-A[i]*mxB[i]-mxA[i]*B[i]+mxA[i]*mxB[i];
	FFT(res1,-1),FFT(res2,-1);
	for (int i=lim-1;i>=0;i--) res1[i].x+=res1[i+1].x;
	for (int i=1;i<lim;i++) res2[i].x+=res2[i-1].x;
	while (Q--)
	{
		int x=min((int)read(),lim);
		print(round(res1[x].x-res2[x-1].x));
	}
	
	return 0;
}