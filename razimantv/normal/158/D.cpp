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

int ar[20000];

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        scanf("%d",ar+i);
    
    int best=-1000000000;
    for(int i=1;i*3<=N;i++)
    {
        if(N%i!=0)continue;
        for(int j=0;j<i;j++)
        {
            int sum=0;
            for(int k=j;k<N;k+=i)
                sum+=ar[k];
            best=max(best,sum);
        }
    }
    printf("%d\n",best);
    return 0;
}