# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>

using namespace std;

int ar[100000];
int yes[100000],no[100000];
int yestotal=0,nototal=0;
char valid[100000];

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",ar+i);
        if(ar[i]<0)
        {
            no[(-ar[i])-1]++;
            nototal++;
        }
        else
        {
            yes[ar[i]-1]++;
            yestotal++;
        }
    }
    
    int cntvalid=0;
    for(int i=0;i<N;i++)
    {
        if(yes[i]+nototal-no[i]==M)
        {
            valid[i]=1;
            cntvalid++;
        }
    }
    
    for(int i=0;i<N;i++)
    {
        int j;
        if(ar[i]<0)
        {
            j=-ar[i]-1;
            if(valid[j]==0)printf("Truth\n");
            else if(cntvalid==1)printf("Lie\n");
            else printf("Not defined\n");
        }
        else
        {
            j=ar[i]-1;
            if((valid[j]==1)&&(cntvalid==1))printf("Truth\n");
            else if(valid[j]==1)printf("Not defined\n");
            else printf("Lie\n");
        }
    }
    return 0;
}