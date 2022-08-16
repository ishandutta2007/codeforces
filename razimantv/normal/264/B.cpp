# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

char notprime[100001];
vector<int> factors[100001];
int longest[100001];

int main()
{
	for(int i=2;i<100001;i++)
	{
		if(notprime[i])continue;
		for(int j=i;j<100001;j+=i)
		{
			notprime[j]=1;
			factors[j].push_back(i);
		}
	}

	int N;
	scanf("%d",&N);

	int ans=1;

	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);

		int good=1;
		for(int j=0;j<factors[a].size();j++)
			good=max(good,longest[factors[a][j]]+1);
		ans=max(ans,good);
		
		for(int j=0;j<factors[a].size();j++)
			longest[factors[a][j]]=good;	
	}
	printf("%d\n",ans);
	return 0;
}