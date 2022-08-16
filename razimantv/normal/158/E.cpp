# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>
# include <queue>
# include <string>

using namespace std;

int start[4001],dur[4001];
int earliestend[4001][4001];

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    
    for(int i=0;i<N;i++)
        scanf("%d%d",start+i,dur+i);
    start[N]=86401;
    
    for(int i=0;i<=N;i++)
        for(int j=i+1;j<=K;j++)
            earliestend[i][j]=86401;
    for(int i=1;i<=N;i++)
    {
        earliestend[i][0]=max(earliestend[i-1][0]+1,start[i-1])+dur[i-1]-1;
        for(int j=1;j<=K;j++)
            earliestend[i][j]=min(earliestend[i-1][j-1],max(earliestend[i-1][j]+1,start[i-1])+dur[i-1]-1);
    }
            
    int best=0;
    for(int i=K;i<=N;i++)
    {
        best=max(best,start[i]-earliestend[i][K]-1);
    }
    printf("%d\n",best);
    return 0;
}