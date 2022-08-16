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
# include <functional>

using namespace std;

int scr[50];

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    
    for(int i=0;i<N;i++)
        scanf("%d",scr+i);
    int ret=0;
    for(int i=0;i<N;i++)
        if(scr[i]>=max(scr[K-1],1))ret++;
    printf("%d\n",ret);
    return 0;
}