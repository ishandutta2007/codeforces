#include<bits/stdc++.h>
using namespace std;
const int N=110;

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
int a[N];

int main()
{
	int T=read();
	while (T--)
	{
		bool flag=1;
		int n=read(),m=read(),k=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<n;i++)
		if (a[i]>=a[i+1]-k)
		{
			int next=max(a[i+1]-k,0),tot=a[i]-next;
			m+=tot;
		}
		else
		{
			int next=max(a[i+1]-k,0),tot=next-a[i];
			m-=tot;
			if (m<0)
			{
				puts("NO");
				flag=0;
				break;
			}
		}
		if (flag) puts("YES");
	}

	return 0;
}