#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;

inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(int x)
{
    if (x<0)
    {
        putchar('-');
        x=-x;
    }
    if (x<10)
    {
        putchar(x+'0');
        return;
    }
    write(x/10);
    putchar(x%10+'0');
}
void print(int x,int y)
{
	write(x);
	putchar(' ');
	write(y);
	putchar('\n');
}

int main()
{
	int t=read();
	while (t--)
	{
		int a=read(),b=read(),c=read(),d=read(),e=read();
		int x=(double)a/(double)c+1-eps,y=(double)b/(double)d+1-eps;
		if (x+y>e) puts("-1");
			  else print(x,y);
	}

	return 0;
}