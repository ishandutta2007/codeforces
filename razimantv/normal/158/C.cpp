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
# include <sstream>
# include <cassert>

using namespace std;

int end=0;
char inp[301],distruct[5000][201];

void work(char *str)
{
    if(str[0]=='/')str++;
    if(str[0]==0)return;
    if(str[0]=='.')
    {
        end--;
        assert(end>=0);
        work(str+2);
        return;
    }
    int i=0;
    for(;str[i]!=0&&str[i]!='/';i++)
        distruct[end][i]=str[i];
    distruct[end++][i]=0;
    work(str+i);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",inp);
        if(inp[0]=='p')
        {
            printf("/");
            for(int i=0;i<end;i++)
                printf("%s/",distruct[i]);
            printf("\n");
            continue;
        }
        scanf("%s",inp);
        if(inp[0]=='/')end=0,work(inp+1);
        else work(inp);
    }
    return 0;
}