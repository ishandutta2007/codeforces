#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <deque>
#include <map>
#include <vector>
using namespace std;

bool nprime[2000000];
int i,j;
int tmp;
vector <int> emirp;
int n;

int rev(int x)
{
    int ret=0;
    while (x>0)
    {
        ret=10*ret+x%10;
        x/=10;
    }
    return ret;
}
int main()
{
    nprime[1]=true;
    for (i=2;i<=1000;++i)
        if (!nprime[i])
            for (j=i*i;j<=1000000;j+=i)
                nprime[j]=true;
    for (i=1;i<=1000000;++i)
        if (!nprime[i])
        {
            tmp=rev(i);
            if(tmp!=i && !nprime[tmp])
                emirp.push_back(i);
        }
    scanf("%d",&n);
    printf("%d\n",emirp[n-1]);
}