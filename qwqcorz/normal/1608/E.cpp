#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int x[N],y[N],t[N],c[N],b[N],cntx,cnty,n;
int tot[N],totx[N][2],toty[N][2],sumx[N][2],sumy[N][2];
bool solve(int k)
{
	for (int i=1;i<=n;i++) totx[i][0]=totx[i][1]=toty[i][0]=toty[i][1]=tot[i]=0;
	for (int i=1;i<=n;i++) tot[x[i]]+=c[i]==1;
	int now=0,zyk=0;
	for (int i=1;i<=cntx;i++) if ((now+=tot[i])>=k){zyk=i;break;}
	for (int i=1;i<=n;i++) if (c[i]>1&&x[i]>zyk) totx[x[i]][c[i]-2]++,toty[y[i]][c[i]-2]++;
	for (int j=0;j<=1;j++)
	{
		for (int i=1;i<=cntx;i++) sumx[i][j]=sumx[i-1][j]+totx[i][j];
		for (int i=1;i<=cnty;i++) sumy[i][j]=sumy[i-1][j]+toty[i][j];
	}
	for (int i=1;i<cntx;i++) if (sumx[i][0]>=k&&sumx[cntx][1]-sumx[i][1]>=k) return 1;
	for (int i=1;i<cnty;i++) if (sumy[i][0]>=k&&sumy[cnty][1]-sumy[i][1]>=k) return 1;
	return 0;
}
bool check(int k)
{
	int p[4]={0,1,2,3};
	do
	{
		for (int i=1;i<=n;i++) c[i]=p[t[i]];
		if (solve(k)) return 1;
		for (int i=1;i<=n;i++) x[i]=cntx+1-x[i];
		if (solve(k)) return 1;
		for (int i=1;i<=n;i++) x[i]=cntx+1-x[i];
		for (int i=1;i<=n;i++) swap(x[i],y[i]);
		swap(cntx,cnty);
		if (solve(k)) return 1;
		for (int i=1;i<=n;i++) x[i]=cntx+1-x[i];
		if (solve(k)) return 1;
		for (int i=1;i<=n;i++) x[i]=cntx+1-x[i];
		for (int i=1;i<=n;i++) swap(x[i],y[i]);
		swap(cntx,cnty);
	}while (next_permutation(p+1,p+4));
	return 0;
}
void GreenDay()
{
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read(),t[i]=read();
	for (int i=1;i<=n;i++) b[i]=x[i];
	sort(b+1,b+1+n);
	cntx=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) x[i]=lower_bound(b+1,b+1+cntx,x[i])-b;
	for (int i=1;i<=n;i++) b[i]=y[i];
	sort(b+1,b+1+n);
	cnty=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) y[i]=lower_bound(b+1,b+1+cnty,y[i])-b;
	int l=1,r=n/3;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
				   else r=mid-1;
	}
	print(r*3);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}