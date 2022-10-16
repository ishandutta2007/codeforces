#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long b[2],lis[100069],c=0;
bitset<100069> a,spc;
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,ln;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=1;i<=ln;i++)
	{
		a[i]=s[i-1]-'0';
		if(a[i])
		{
			lis[i]=max(b[0],b[1])+1;
		}
		else
		{
			lis[i]=b[0]+1;
		}
		b[a[i]]=lis[i];
		if(a[i]&&!a[i-1])
		{
			pq.push(mp(-(lis[i]-lis[i-1]-1),i-1));
		}
		if(!a[i]&&a[i-1])
		{
			spc[i-1]=1;
		}
	}
	for(i=1;i<=ln;i++)
	{
		for(;!pq.empty()&&pq.top().sc<i;pq.pop());
		if(a[i]&&!spc[i]&&b[0]<b[1]&&(pq.empty()||c<-pq.top().fr))
		{
			a[i]=0;
			c++;
			b[0]++;
		}
	}
	for(i=1;i<=ln;i++)
	{
		printf("%d",(bool)a[i]);
	}
	printf("\n");
}