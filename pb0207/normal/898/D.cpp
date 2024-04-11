#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;

const int N=2e6+1e3+7;

int n,m,k;
 
int a[N],f[N];

int c[N];

void add(int x,int d)
{
	while(x<=n)
	{
		c[x]+=d;
		x+=x&-x;
	}
}

int qr(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=x&-x;
	}
	return ret;
}

int sum(int x,int y)
{
	return qr(y)-qr(x-1);
}


int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(k==1)
	{
		printf("%d\n",n);
		return 0;
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;++i)
		add(i,1);
	for(int i=1;i<=n;++i)
	{
		if(sum(1,i)<k)
			continue;
		int l=1,r=i+1;
		while(r-l>1)
		{
			int mid=l+r+1>>1;
			if(sum(mid,i)>=k)
				l=mid;
			else 
				r=mid;
		}
		if(a[i]-a[l]<m)
		{
			add(i,-1);
			cnt++;
		}
	}
	cout<<cnt;
}