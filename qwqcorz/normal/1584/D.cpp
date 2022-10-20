#include<bits/stdc++.h>
#define int long long
using namespace std;

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
int get(int n)
{
	return ceil(sqrt(n*2));
}
int Ask(int l,int r)
{
	printf("? ");
	print(l,' '),print(r);
	fflush(stdout);
	int ret=read();
	if (ret<0) exit(0);
	return ret;
}
void Answer(int i,int j,int k)
{
	printf("! ");
	print(i,' '),print(j,' '),print(k);
	fflush(stdout);
}
void Multi_test_no_horses()
{
	int n=read(),l=1,r=n;
	int sum=Ask(1,n);
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (Ask(1,mid)<sum) l=mid+1;
					   else r=mid-1;
	}
	int k=l;
	int len2=sum-Ask(1,k-1),j=k-len2;
	int len1=get(sum-len2*(len2+1)/2),i=j-len1;
	Answer(i,j,k);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}