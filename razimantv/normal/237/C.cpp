# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <queue>
# include <cstring>
# include <cctype>

using namespace std;

char notprime[1000001];
int cntprimes[1000001];

bool work(int a,int b,int l,int k)
{
	for(int i=a;i+l-1<=b;i++)
		if(cntprimes[i+l-1]-cntprimes[i-1]<k)return false;
	return true;
}

int main()
{
	int i;
	for(i=2;i*i<1000001;i++)
	{
		if(notprime[i])
		{
			cntprimes[i]=cntprimes[i-1];
			continue;
		}
		cntprimes[i]=cntprimes[i-1]+1;

		for(int j=i*i;j<1000001;j+=i)
			notprime[j]=1;
	}

	for(;i<1000001;i++)
		if(!notprime[i])
			cntprimes[i]=cntprimes[i-1]+1;
		else
			cntprimes[i]=cntprimes[i-1];

	int a,b,k;
	cin>>a>>b>>k;

	if(cntprimes[b]-cntprimes[a-1]<k)
	{
		cout<<-1<<endl;
		return 0;
	}

	int start=k-1,end=b-a+1;
	while(end-start>1)
	{
		int mid=(end+start)/2;
		if(work(a,b,mid,k))end=mid;
		else start=mid;
	}

	cout<<end<<endl;

	return 0;
}