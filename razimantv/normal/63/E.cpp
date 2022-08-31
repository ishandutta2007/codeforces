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

char iswinning[1<<19];
char inp[2];
int allowedlines[][5]={{0,1,2},{3,4,5,6},{7,8,9,10,11},{12,13,14,15},{16,17,18},
                       {0,3,7},{1,4,8,12},{2,5,9,13,16},{6,10,14,17},{11,15,18},
                       {2,6,11},{1,5,10,15},{0,4,9,14,18},{3,8,13,17},{7,12,16}};

int allowedcount[]={3,4,5,4,3,3,4,5,4,3,3,4,5,4,3};
int allowedstates[141];

int main()
{
    int upto=0;
    for(int i=0;i<15;i++)
    {
        int st;
        for(int j=0;j<allowedcount[i];j++)
        {
            for(int k=0;k+j<allowedcount[i];k++)
            {
                st=0;
                for(int l=0;l<=k;l++)
                    st|=(1<<allowedlines[i][j+l]);
                allowedstates[upto++]=st;
            }
        }
    }
    int mask=1,state=0;
    for(int i=0;i<19;i++)
    {
        scanf("%s",inp);
        if(inp[0]=='O')state|=mask;
        mask<<=1;
    }
    for(int i=1;i<=state;i++)
    {
        if(i&(~state))continue;
        for(int j=0;j<upto;j++)
        {
            if(((i&allowedstates[j])==allowedstates[j])&&!iswinning[i^allowedstates[j]])
            {
                iswinning[i]=1;
                break;
            }
        }
    }
    if(iswinning[state])printf("Karlsson\n");
    else printf("Lillebror\n");
    return 0;
}