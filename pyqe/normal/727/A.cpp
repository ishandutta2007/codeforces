#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,k,c=0,p,i;
	vector<long long> v;
	queue<long long> q;
	map<long long,long long> m;
	map<long long,bool> vtd;
	
	scanf("%lld%lld",&a,&b);
	if(a>b)
	{
		printf("NO\n");
		return 0;
	}
	else if(a==b)
	{
		printf("YES\n1\n%lld\n",a);
		return 0;
	}
	q.push(a);
	vtd[a]=true;
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		if(k*2==b||k*10+1==b)
		{
			m[b]=k;
			break;
		}
		if(k*2<b&&!vtd[k*2])
		{
			q.push(k*2);
			m[k*2]=k;
			vtd[k*2]=true;
		}
		if(k*10+1<b&&!vtd[k*10+1])
		{
			q.push(k*10+1);
			m[k*10+1]=k;
			vtd[k*10+1]=true;
		}
	}
	if(m[b]==0)
	{
		printf("NO\n");
		return 0;
	}
	p=b;
	while(p>0)
	{
		v.push_back(p);
		p=m[p];
		c++;
	}
	printf("YES\n%lld\n",c);
	for(i=c-1;i>=0;i--)
	{
		if(i<c-1)
		{
			printf(" ");
		}
		printf("%lld",v[i]);
	}
	printf("\n");
}