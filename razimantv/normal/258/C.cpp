# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int cum[100001];
vector<int>facs[100001];
const int MOD=1000000007;

long long pow(long long a,int b)
{
	long long ret=1;
	for(int i=1;i<=b;i<<=1)
	{
		if(b&i)ret=(ret*a)%MOD;
		a=(a*a)%MOD;
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d",&N);

	int big=0;
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		cum[a]++;
		big=max(big,a);
	}

	for(int i=1;i<=big;i++)
		cum[i]+=cum[i-1];
	
	for(int i=1;i<=big;i++)
		for(int j=i;j<=big;j+=i)
			facs[j].push_back(i);
	
	int ret=1;
	for(int i=2;i<=big;i++)
	{
		long long thisret=1;
		int seen=0;
		for(int j=0;j<facs[i].size();j++)
		{
			int x=cum[facs[i][j]-1];
			thisret=(thisret*pow(j,x-seen))%MOD;
			seen=x;
		}
		int rem=N-seen;
		thisret=(thisret*(pow(facs[i].size(),rem)+(MOD-pow(facs[i].size()-1,rem))))%MOD;
		ret+=thisret;
		if(ret>=MOD)ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}