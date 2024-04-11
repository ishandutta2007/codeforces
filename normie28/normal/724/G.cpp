#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100100,M=200200,P=1000000007;
int ii,i,j,k,n,m,x,y,res,nn,na,n1,ch,En,np;
ll t,a[M],s[N],v,ma,sum;
int h[N],dp[N],z[N],pw2[N],p[N];
struct edge { int s,n;ll v;} E[M<<1];
void R(int &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
void R(ll &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
void E_add(int x,int y,ll v) {
	E[++En].s=y;E[En].v=v;
	E[En].n=h[x];h[x]=En;
	E[++En].s=x;E[En].v=v;
	E[En].n=h[y];h[y]=En;
}
void dfs(int x) {
	p[++np]=x;
	z[x]=1;
	for (int k=h[x];k;k=E[k].n) {
		if (!z[E[k].s]) {
			dp[E[k].s]=dp[x]+1;
			s[E[k].s]=s[x]^E[k].v;
			dfs(E[k].s);
		}
		else {
			if (dp[E[k].s]<dp[x]) {
				ll t=s[x]^s[E[k].s]^E[k].v;
				if (t) a[++na]=t;
			}
		}
	}
}
int main() {
    cin>>n>>m;
	for (i=1;i<=m;i++) {
		R(x);R(y);R(v);
		E_add(x,y,v);
		if (v>ma) ma=v;
	}
	nn=0;
	while ((1ll<<nn+1)<=ma) nn++;
	pw2[0]=1;
	for (i=1;i<=nn;i++) pw2[i]=(pw2[i-1]<<1)%P;
	for (ii=1;ii<=n;ii++) if (!z[ii]) {
		np=na=0;
		sum=0;
		dfs(ii);
		for (i=1;i<=na;i++) {
			for (j=i+1;j<=na;j++) if (a[i]<a[j]) {
				t=a[i];a[i]=a[j];a[j]=t;
			}
			if (!a[i]) break;
			k=nn;
			while (!(a[i]&1ll<<k)) k--;
			for (j=1;j<=na;j++) if (j!=i && (a[j]&1ll<<k)) a[j]^=a[i];
		}
		na=i-1;
		for (i=1;i<=na;i++) sum|=a[i];
		for (i=nn;i>=0;i--) {
			if (sum&1ll<<i) {
				res=((ll) np*(np-1)/2%P*pw2[na-1]%P*pw2[i]+res)%P;
				continue;
			}
			n1=0;
			for (j=1;j<=np;j++) if (s[p[j]]&1ll<<i) n1++;
			res=((ll) (np-n1)*n1%P*pw2[na]%P*pw2[i]+res)%P;
		}
	}
	cout<<res;
}