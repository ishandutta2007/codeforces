#include<bits/stdc++.h>
using namespace std;
const int N=202;

inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(int n)
{
    if (n<0)
    {
        putchar('-');
        n=abs(n);
    }
    if (n<10)
    {
        putchar(n+'0');
        return;
    }
    write(n/10);
    putchar(n%10+'0');
}
void print(int x)
{
	write(x);
	putchar(' ');
}
bool A[N];
int a[N],b[N];

int main()
{
	memset(A,0,sizeof(A));
	int n=read();
	for (int i=1;i<=n;i++) A[a[i]=read()]=1;
	int m=read();
	for (int i=1;i<=m;i++) A[b[i]=read()]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) if (!A[a[i]+b[j]])
	{
		print(a[i]);
		print(b[j]);
		return 0;
	}
}