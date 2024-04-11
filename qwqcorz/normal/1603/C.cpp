#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int S=1e3+5;
const int p=998244353;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int f[2][S],g[2][S],a[N],len[2][S],L[2][S],R[2][S],cnt[2];
void Multi_test_no_horses()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	f[n&1][1]=0,g[n&1][1]=1;
	len[n&1][1]=1;
	L[n&1][1]=R[n&1][1]=a[n];
	cnt[n&1]=1;
	for (int i=n-1;i>=1;i--)
	{
		int t=i&1;
		cnt[t]=0;
		for (int l=1,r;l<=a[i];l=a[i]/(a[i]/l)+1)
		{
			r=a[i]/(a[i]/l);
			bool flag=0;
			if (a[i]%r==0)
			{
				flag=1;
				cnt[t]++;
				L[t][cnt[t]]=R[t][cnt[t]]=a[i]/r;
				len[t][cnt[t]]=r--;
			}
			if (l>r) continue;
			cnt[t]++;
			L[t][cnt[t]]=a[i]/l;
			R[t][cnt[t]]=a[i]/l+1;
			len[t][cnt[t]]=l;
			if (flag)
			{
				swap(L[t][cnt[t]],L[t][cnt[t]-1]);
				swap(R[t][cnt[t]],R[t][cnt[t]-1]);
				swap(len[t][cnt[t]],len[t][cnt[t]-1]);
			}
		}
		for (int j=1;j<=cnt[t];j++) f[t][j]=g[t][j]=0;
		g[t][1]=1;
		for (int j=1,k=1;j<=cnt[t];j++)
		{
			int sumf=0,sumg=0;
			while (k<=cnt[!t]&&L[!t][k]>=R[t][j])
			{
				add(sumf,f[!t][k]);
				add(sumg,g[!t][k]);
				k++;
			}
			f[t][j]=(sumf+1LL*sumg*(len[t][j]-1))%p;
			add(g[t][j],sumg);
			add(ans,f[t][j]);
//			print(len[t][j],' ');
//			print(L[t][j],',');
//			print(R[t][j],':');
//			print(f[t][j]);
		}
//		puts("");
	}
	print(ans);
}
/*
1
4
3 2 1 4

*/

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}