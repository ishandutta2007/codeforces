#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int L[n+1];
    int otvoreno[n+1]={};
    int zatvoreno[n+1]={};
    for(int i=0;i<n;i++)
    {
        scanf("%i",&L[i]);
        if(L[i]>0)
        {
        if(L[i]>i)
        {
            otvoreno[0]++;
        }
        else
        {
            otvoreno[i-L[i]]++;
        }
        zatvoreno[i]++;
        }
    }
    int broj=0;
    int resenje=0;
    for(int i=0;i<n;i++)
    {
        //printf("%i, %i\n",otvoreno[i],zatvoreno[i]);
        broj+=otvoreno[i];
        broj-=zatvoreno[i];
        if(broj==0)
        {
            resenje++;
        }
    }
    printf("%i\n",resenje);
    return 0;
}