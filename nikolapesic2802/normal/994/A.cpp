#include <bits/stdc++.h>

using namespace std;
int dozvoljeno[10];
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    int code[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&code[i]);
    }
    for(int i=0;i<m;i++)
    {
        int d;
        scanf("%i",&d);
        dozvoljeno[d]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(dozvoljeno[code[i]])
        {
            printf("%i ",code[i]);
        }
    }
    return 0;
}