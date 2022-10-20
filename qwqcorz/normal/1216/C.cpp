#include<bits/stdc++.h>
using namespace std;

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
bool a[7][7];
int n,m,X[7],Y[7],cnt=0;
int findx(int x)
{
	for (int i=1;i<=n;i++) if (x==X[i]) return i;
}
int findy(int y)
{
	for (int i=1;i<=m;i++) if (y==Y[i]) return i;
}
struct point
{
	int x,y;
	void readln()
	{
		x=read();
		y=read();
		X[++cnt]=x;
		Y[cnt]=y;
	}
};
struct paper
{
	point p1,p2;
	void readln()
	{
		p1.readln();
		p2.readln();
	}
	void paint(bool b)
	{
		int lx=findx(p1.x),rx=findx(p2.x);
		int ly=findy(p1.y),ry=findy(p2.y);
		for (int i=lx;i<rx;i++)
		for (int j=ly;j<ry;j++) a[i][j]=b;
	}
}w,b1,b2;

int main()
{
	memset(a,0,sizeof(a));
	w.readln();
	b1.readln();
	b2.readln();
	sort(X+1,X+7);
	sort(Y+1,Y+7);
	n=unique(X+1,X+7)-X-1;
	m=unique(Y+1,Y+7)-Y-1;
	w.paint(1);
	b1.paint(0);
	b2.paint(0);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j])
	{
		puts("YES");
		return 0;
	}
	puts("NO");

	return 0;
}