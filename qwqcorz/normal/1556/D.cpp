#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;

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
int OR(int x,int y)
{
	printf("or %d %d\n",x,y);
	fflush(stdout);
	return read();
}
int AND(int x,int y)
{
	printf("and %d %d\n",x,y);
	fflush(stdout);
	return read();
}
int Q(int x,int y)
{
	return OR(x,y)+AND(x,y);
}
int a[N];
void Multi_test_no_horses()
{
	int n=read(),k=read();
	int AB=Q(1,2),AC=Q(1,3),BC=Q(2,3);
	int A_B=AC-BC;
	int A=(AB+A_B)/2;
	int B=AB-A;
	int C=AC-A;
	a[1]=A,a[2]=B,a[3]=C;
	for (int i=4;i<=n;i++) a[i]=Q(1,i)-a[1];
	nth_element(a+1,a+k,a+1+n);
	printf("finish %d\n",a[k]);
	fflush(stdout);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}