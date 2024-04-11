#include<bits/stdc++.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 1000010

int cnt[N]={0};
vector<int> v[N];

void update(int lo,int hi)
{
	cnt[lo]++;
	cnt[hi+1]--;
}

int main()
{
	int n,c,i,j;
	sd(n);sd(c);
	for(i=0;i<n;++i)
	{
		int l;
		sd(l);
		v[i].resize(l);
		for(j=0;j<l;++j)
			sd(v[i][j]);
	}

	for(i=0;i<n-1;++i)
	{
		for(j=0;j<min((int)v[i].size(),(int)v[i+1].size());++j)
			if(v[i][j]!=v[i+1][j])
				break;

		if(j==(int)v[i].size())
		{
			update(0,c-1);
			continue;
		}

		if(j==(int)v[i+1].size())
			continue;
		int lo,hi;
		if(v[i][j]<v[i+1][j])
		{
			update(0,c-v[i+1][j]);
			update(c+1-v[i][j],c-1);
		}
		else
			update(c+1-v[i][j],c-v[i+1][j]);
	}
	for(i=0;i<c;++i)
	{
		cnt[i]+=cnt[i-1];
		if(cnt[i]==n-1)
			break;
	}
	if(i==c)
		i=-1;
	printf("%d\n",i);
}