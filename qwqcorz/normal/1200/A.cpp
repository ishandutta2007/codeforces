#include<bits/stdc++.h>
using namespace std;
const int N=10;

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
bool a[N];

int main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		char c=getchar();
		while (c!='L'&&c!='R')
		{
			if ('0'<=c&&c<='9') break;
			c=getchar();
		}
		if ('0'<=c&&c<='9') a[c-'0']=0;
		if (c=='L')
		{
			int now=0;
			while (a[now]) now++;
			a[now]=1;
		}
		if (c=='R')
		{
			int now=9;
			while (a[now]) now--;
			a[now]=1;
		}
	}
	for (int i=0;i<=9;i++) write(a[i]);

	return 0;
}