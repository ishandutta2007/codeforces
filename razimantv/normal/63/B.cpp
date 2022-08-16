# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>
# include <queue>

using namespace std;
int counter[101];

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		counter[x]++;
	}
	
	int ret=0;
	while(1)
	{
		bool flag=false;
		for(int i=K-1;i>0;i--)
			if(counter[i])
			{
				counter[i+1]++;
				counter[i]--;
				flag=true;
			}
		if(flag)ret++;
		else break;
	}
	printf("%d\n",ret);
	return 0;
}