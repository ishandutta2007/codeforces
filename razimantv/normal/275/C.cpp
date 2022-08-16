# include <cstdio>
# include <algorithm>
# include <set>

using namespace std;

long long ar[100000];
set<long long>numset;

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%Ld",ar+i);
	sort(ar,ar+N);
	
	int ret=0;
	for(int i=0;i<N;i++)
	{
		if((ar[i]%K==0)&&(numset.count(ar[i]/K)!=0))continue;
		ret++;
		numset.insert(ar[i]);
	}
	printf("%d\n",ret);
	return 0;
}