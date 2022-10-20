#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long double inf=1e99L;
const long double eps=1e-9L;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct point
{
	long double x,y;
	point operator -(point a){return (point){x-a.x,y-a.y};}
	long double operator *(point a){return x*a.y-y*a.x;}
	long double operator %(point a){return x*a.x+y*a.y;}
	bool operator <(const point &a)const{return x!=a.x?x<a.x:y<a.y;}
	void output(char c='\n'){printf("%Lf,%Lf%c",x,y,c);}
};
vector<point>a,b,c;
long double getang(point x,point y,point z){return ((x-z)%(y-z))/((x-z)*(y-z));}
bool check(point u,point v)
{
//	u.output(' '),v.output();
	long double l=-1e99L,r=1e99L;
	for (auto i:a)
	{
		long double tmp=getang(u,v,i),myh=(u-i)*(v-i);
		if (!myh) continue;
		if (myh<0) r=min(r,tmp);
			  else l=max(l,tmp);
	}
//	printf("%.9Lf %.9Lf\n",l,r);
	for (auto i:b)
	{
		long double tmp=getang(u,v,i),myh=(u-i)*(v-i);
		if (!myh)
		{
			if (i.x<min(u.x,v.x)||i.x>max(u.x,v.x)||i.y<min(u.y,v.y)||i.y>max(u.y,v.y)) continue;
			return 0;
		}
		if (myh>0) r=min(r,tmp-eps);
			  else l=max(l,tmp+eps);
	}
//	printf("%.9Lf %.9Lf\n",l,r);
	return l<=r;
}
bool cdq(int l,int r)
{
	if (r-l==1) return 0;
	long double mn=inf; int id=l;
	for (int i=l+1;i<r;i++)
	{
		long double tmp=getang(c[l],c[r],c[i]);
		if (tmp<mn) mn=tmp,id=i;
	}
	return check(c[l],c[id])||check(c[r],c[id])||cdq(l,id)||cdq(id,r);
}
bool solve(vector<point>a,vector<point>b)
{
	::a=a,::b=b;
	c.clear();
	sort(a.begin(),a.end());
	int top=0;
	for (auto i:a)
	{
		while (top>1&&(i-c[top-1])*(c[top-1]-c[top-2])>=0) c.pop_back(),top--;
		c.push_back(i),top++;
	}
	int tmp=top;
	a.pop_back();
	reverse(a.begin(),a.end());
	for (auto i:a)
	{
		while (top>tmp&&(i-c[top-1])*(c[top-1]-c[top-2])>=0) c.pop_back(),top--;
		c.push_back(i),top++;
	}
	c.pop_back(),top--;	
	int n=c.size();
	if (n==1) return 1;
	return check(c[0],c[n-1])||cdq(0,n-1);
}

signed main()
{
	int n=read(),m=read();
	vector<point>a(n),b(m);
	for (int i=0;i<n;i++) a[i].x=read(),a[i].y=read();
	for (int i=0;i<m;i++) b[i].x=read(),b[i].y=read();
	puts(solve(a,b)||solve(b,a)?"YES":"NO");
	
	return 0;
}