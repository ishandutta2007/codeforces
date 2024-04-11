#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;

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
int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}
struct Vector
{
	int x,y;
	int operator *(const Vector &a)const
	{
		return x*a.y-y*a.x;
	}
	Vector operator *(const int &a)const
	{
		return (Vector){x*a,y*a};
	}
	Vector operator /(const int &a)const
	{
		return (Vector){x/a,y/a};
	}
};
struct point
{
	int x,y;
	bool operator <(const point &a)const
	{
		return y==a.y?x<a.x:y<a.y;
	}
	bool operator ==(const point &a)const
	{
		return x==a.x&&y==a.y;
	}
}p[N],pp[N*N];
struct segment
{
	int x1,y1,x2,y2,tot;
	void push(int X1,int Y1,int X2,int Y2)
	{
		x1=X1;
		y1=Y1;
		x2=X2;
		y2=Y2;
		tot=labs(gcd(x2-x1,y2-y1))+1;
	}
	bool have(point a)
	{
//		return x1<=a.x&&a.x<=x2&&y1<=a.y&&a.y<=y2&&(a.x-x1)*(y2-a.y)==(x2-a.x)*(a.y-y1);
		return ((x1<=a.x&&a.x<=x2)||(x2<=a.x&&a.x<=x1))&&
			   ((y1<=a.y&&a.y<=y2)||(y2<=a.y&&a.y<=y1))&&
			   (Vector){x1-a.x,y1-a.y}*(Vector){x2-a.x,y2-a.y}==0;
	}
}a[N];
point cross(segment A,segment B)
{
	Vector u=(Vector){B.x1-A.x1,B.y1-A.y1};
	Vector v=(Vector){B.x2-B.x1,B.y2-B.y1};
	Vector w=(Vector){A.x2-A.x1,A.y2-A.y1};
	int up=w*u,down=v*w;
//	print(w.x,',');
//	print(w.y);
	if (down==0) return (point){0,0};
	Vector AO=v*up/down;
	return (point){B.x1+AO.x,B.y1+AO.y};
}

signed main()
{
	int n=read(),ans=0,cntt=0;
	for (int i=1;i<=n;i++)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		a[i].push(x1,y1,x2,y2);
	}
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=1;j<=n;j++)
		if (i!=j)
		{
			point tmp=cross(a[i],a[j]);
//			print(tmp.x,' ');
//			print(tmp.y);
			if (a[i].have(tmp))
			if (a[j].have(tmp))
			{
				p[++cnt]=tmp;
				pp[++cntt]=tmp;
			}
		}
//		print(cnt);
		sort(p+1,p+1+cnt);
		cnt=unique(p+1,p+1+cnt)-p-1;
		ans+=a[i].tot-cnt;
	}
	sort(pp+1,pp+1+cntt);
	cntt=unique(pp+1,pp+1+cntt)-pp-1;
	print(ans+cntt);

	return 0;
}
/*
2
1 1 3 3
1 3 3 1
*/