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

char name[100][11];
char status[11];
char type[100];

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%s%s",name[i],status);
        if(status[0]=='r')type[i]=0;
        else if(status[0]=='w'||status[1]=='h')type[i]=1;
        else if(status[0]=='m')type[i]=2;
        else type[i]=3;
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<N;j++)
            if(type[j]==i)printf("%s\n",name[j]);
    return 0;
}