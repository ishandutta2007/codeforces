#include <bits/stdc++.h>
#define MAXN 2507
using namespace std;
struct point {
    long long x,y;
    int ind;
};
int n;
point a[MAXN];
vector<point> u,l;
bool cmp(point p,point q) 
{
    return p.ind<q.ind;
}
long long orient(point p,point q,point r) 
{
    return (q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);
}
bool operator <(point p,point q) 
{
    return orient(p,q,a[0])>0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].ind=i;
	}
	long long res=0;
	for(int i=0;i<n;i++)
	{
		sort(a,a+n,cmp);
		swap(a[i],a[0]);
		u.clear(); l.clear();
		for(int i=1;i<n;i++)
		{
			if(a[i].x>=a[0].x) u.push_back(a[i]);
			else l.push_back(a[i]);
		}
		sort(u.begin(),u.end());
		sort(l.begin(),l.end());
		for(int i=1;i<=u.size();i++) a[i]=u[i-1];
		for(int i=u.size()+1;i<n;i++) a[i]=l[i-u.size()-1];
		int t=1;
		long long tmp=0;
		for(int j=1;j<n;j++)
		{
			while(orient(a[0],a[j],a[(t-1)%(n-1)+1])>=0 && t<n-1+j) t++;
			long long v=t-j-1;
			tmp=tmp+v*(v-1)/2;
		}
		long long nk=n-1;
		nk=(nk*(nk-1)*(nk-2))/6;
		res+=nk-tmp;
	}
	res*=((long long)n-4LL);
	res=res/2LL;
	printf("%I64d",res);
}