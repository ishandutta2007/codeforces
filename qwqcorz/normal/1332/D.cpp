#include<bits/stdc++.h>
using namespace std;
const int inf=(1<<18)-1;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[5][6];

int main()
{
    puts("4 5");
    int k=read();
    a[1][1]=inf;
	a[1][2]=k;
	a[2][1]=inf-k;
    for (int i=2;i<=4;i++)
	{
        a[1][i]=a[i][4]=k;
        a[i][1]=a[4][i]=inf-k;
    }
    a[4][4]=inf;
    a[4][5]=k;
    for (int i=1;i<=4;i++)
	{
        for (int j=1;j<=5;j++) print(a[i][j],' ');
        putchar('\n');
    }

	return 0;
}