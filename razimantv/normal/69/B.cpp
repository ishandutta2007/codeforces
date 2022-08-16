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

int st[100],end[100],ttime[100],bet[100];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	
	for(int i=0;i<M;i++)
		scanf("%d%d%d%d",st+i,end+i,ttime+i,bet+i);
	
	int ret=0;
	for(int i=1;i<=N;i++)
	{
		int t=1001,add=0;
		for(int j=0;j<M;j++)
		{
			if(st[j]<=i&&end[j]>=i&&ttime[j]<t)
			{
				t=ttime[j];
				add=bet[j];
			}
		}
		ret+=add;
	}
	printf("%d\n",ret);
	return 0;
}