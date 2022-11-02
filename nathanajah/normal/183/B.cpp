#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int maxi[2000000];
int n,m,i,j,k;
long long x[300],y[300];
long long x1,yy1,x2,y2;
long long tmp;
long long di;

int main()
{
    scanf("%d %d",&n,&m);
    for (i=0;i<m;++i)
        scanf("%d %d",&x[i],&y[i]);
    for (i=1;i<=n;++i)
        maxi[i]=1;
    for (i=0;i<m;++i)
        for (j=1;j<m;++j)
        {
            x1=x[i];
            x2=x[j];
            yy1=y[i];
            y2=y[j];
            if (yy1!=y2)
            {
                tmp=yy1*(x2-x1);
                if (tmp%(y2-yy1)==0)
                {
                    tmp=2;
                    for (k=0;k<m;++k)
                        if (k!=i && k!=j)
                        {
                            if ((x2-x1)*(y[k]-yy1)-(y2-yy1)*(x[k]-x1)==0)
                                ++tmp;
                        }
                    di=(x1+(yy1*(x1-x2))/(y2-yy1));
                    if (di>=1 && di<=n)
                        maxi[di]=max(maxi[di],(int)tmp);
                }
            }
        }
    tmp=0;
    for (i=1;i<=n;++i)
        tmp+=maxi[i];
    printf("%d\n",tmp);
}