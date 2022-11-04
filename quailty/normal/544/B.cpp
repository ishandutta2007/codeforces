#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(k>n*n-n*n/2)printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i+j)%2==0 && k>0)
                {
                    printf("L");
                    k--;
                }
                else printf("S");
            }
            printf("\n");
        }
    }
    return 0;
}