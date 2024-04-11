#include <bits/stdc++.h>

using namespace std;

long long n,d;
queue<long long> q;
map<long long,long long> nr;

int main()
{
	long long i,k,l,w,ml=1,kk;
	
	scanf("%lld%lld",&d,&n);
	for(i=0;i<d-1;i++)
	{
		ml*=10;
	}
	q.push(n);
	nr[n]=1;
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		for(kk=k;kk;kk/=10)
		{
			w=kk%10;
			if(w>=2)
			{
				l=k*w;
				if(l>=ml)
				{
					printf("%lld\n",nr[k]);
					return 0;
				}
				if(!nr[l])
				{
					q.push(l);
					nr[l]=nr[k]+1;
				}
			}
		}
	}
	printf("-1\n");
}