#include<bits/stdc++.h>
using namespace std;

int n,k,id[5010];
int f[5010][5010];
struct node{long long x,t;}a[5010];

bool cmp(node a,node b) {return a.x<b.x;}
bool cmp2(int x,int y) {return a[x].t<a[y].t;}

int find(long long x)
{
	int l=1,r=n,ans=n+1,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (a[mid].x>=x) ans=mid,r=mid-1; else l=mid+1;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%lld%lld",&a[i].t,&a[i].x),id[i]=i;
	sort(a+1,a+1+n,cmp),sort(id+1,id+1+n,cmp2);
	if (abs(a[id[1]].x)>a[id[1]].t) return puts("NO"),0;
	long long la=0,x=0,t=0;
	for (int i=1; i<=n; i++)
	{
		if (a[id[i]].t-t<abs(a[id[i]].x-x)) break;
		if (i==n) return puts("YES"),0;
		bool bo=0;
		if (a[id[i]].x>x) a[id[i]].x=-a[id[i]].x,x=-x,bo=1;
		long long len=((a[id[i]].t-t)-abs(a[id[i]].x-x))/2,r=(la-t<=len?x+len:a[id[i]].x+(a[id[i]].t-la)),l=(a[id[i]].t-la<=len?a[id[i]].x-(a[id[i]].t-la):a[id[i]].x-len);
		if (bo) swap(l,r),a[id[i]].x=-a[id[i]].x,x=-x,r=-r,l=-l;
		f[id[i]][find(l)]+=1,f[id[i]][find(r+1)]-=1;
		t=max(t+abs(a[id[i]].x-x),la),la=a[id[i]].t,x=a[id[i]].x;
	}
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<=n; j++) f[id[i]][j]+=f[id[i]][j-1];
		if (f[id[i]][id[i]])
		{
			la=t=a[id[i]].t,x=a[id[i]].x;
			for (int j=i+1; j<=n; j++)
			{
				swap(i,j);
				if (a[id[i]].t-t<abs(a[id[i]].x-x)) {swap(i,j); break;}
				if (i==n) return puts("YES"),0;
				bool bo=0;
				if (a[id[i]].x>x) a[id[i]].x=-a[id[i]].x,x=-x,bo=1;
				long long len=((a[id[i]].t-t)-abs(a[id[i]].x-x))/2,r=(la-t<=len?x+len:a[id[i]].x+(a[id[i]].t-la)),l=(a[id[i]].t-la<=len?a[id[i]].x-(a[id[i]].t-la):a[id[i]].x-len);
				if (bo) a[id[i]].x=-a[id[i]].x,x=-x,swap(l,r),r=-r,l=-l;
				f[id[i]][find(l)]+=1,f[id[i]][find(r+1)]-=1;
				t=max(t+abs(a[id[i]].x-x),la),la=a[id[i]].t,x=a[id[i]].x;
				swap(i,j);
			}
		}
		for (int j=i+2; j<=n; j++)
			if (f[id[i]][id[j]]&&abs(a[id[i+1]].x-a[id[i]].x)<=abs(a[id[i+1]].t-a[id[i]].t)) 
				f[id[i+1]][id[j]]+=1,f[id[i+1]][id[j]+1]-=1;
		if (f[id[i]][id[i+1]])
		{
			la=a[id[i+1]].t,x=a[id[i]].x,t=a[id[i]].t;
			if (i==n-1) return puts("YES"),0;
			for (int j=i+2; j<=n; j++)
			{
				swap(i,j);
				if (a[id[i]].t-t<abs(a[id[i]].x-x)) {swap(i,j); break;}
				if (i==n) return puts("YES"),0;
				bool bo=0;
				if (a[id[i]].x>x) a[id[i]].x=-a[id[i]].x,x=-x,bo=1;
				long long len=((a[id[i]].t-t)-abs(a[id[i]].x-x))/2,r=(la-t<=len?x+len:a[id[i]].x+(a[id[i]].t-la)),l=(a[id[i]].t-la<=len?a[id[i]].x-(a[id[i]].t-la):a[id[i]].x-len);
				if (bo) a[id[i]].x=-a[id[i]].x,x=-x,swap(l,r),r=-r,l=-l;
				f[id[i]][find(l)]+=1,f[id[i]][find(r+1)]-=1;
				t=max(t+abs(a[id[i]].x-x),la),la=a[id[i]].t,x=a[id[i]].x;
				swap(i,j);
			}
		}
	}
	for (int j=1; j<=n; j++) f[id[n]][j]+=f[id[n]][j-1];
	puts(f[id[n]][id[n]]?"YES":"NO");
	return 0;
}