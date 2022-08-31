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

char state[1000][1000];
int vectors[20][2];

int main()
{
	int X,Y,N,D;
	cin>>X>>Y>>N>>D;
	
	for(int i=0;i<N;i++)
		cin>>vectors[i][0]>>vectors[i][1];
	
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
		{
			int x=i-500,y=j-500;
			if(x*x+y*y>D*D)state[i][j]=2;
		}
	for(int i=999;i>=0;i--)
		for(int j=999;j>=0;j--)
		{
			if(state[i][j]==0)state[i][j]=1;
			if(state[i][j]==1)
			{
				for(int k=0;k<N;k++)
					if(i-vectors[k][0]>=0&&j-vectors[k][1]>=0)
						state[i-vectors[k][0]][j-vectors[k][1]]=2;
			}
		}
	printf("%s\n",state[X+500][Y+500]==2?"Anton":"Dasha");
	
	return 0;
}