# include <iostream>
# include <set>

using namespace std;

long long xorarray[100001];
set<long long> exist[40];

void insert(long long num)
{
	long long temp=0,mask=1ll<<39;
	for(int i=0;i<40;i++,mask>>=1)
	{
		if(mask&num)temp^=mask;
		exist[i].insert(temp);
	}
}

long long getbest(long long num)
{
	long long mask=1ll<<39,ret=0;
	for(int i=0;i<40;i++,mask>>=1)
	{
		if(!(mask&num))ret^=mask;
		if(!exist[i].count(ret))ret^=mask;
	}
	return ret;
}

int main()
{
	int N;
	cin>>N;

	for(int n=1;n<=N;n++)
	{
		cin>>xorarray[n];
		xorarray[n]^=xorarray[n-1];
	}

	for(int i=0;i<40;i++)
		exist[i].insert(0);

	long long ret=0;
	for(int i=1;i<=N;i++)
	{
		insert(xorarray[i]);
		ret=max(ret,getbest(xorarray[i]^xorarray[N])^(xorarray[i]^xorarray[N]));
	}

	cout<<ret<<endl;
	return 0;
}