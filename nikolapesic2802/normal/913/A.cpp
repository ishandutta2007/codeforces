#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    if(n<=30)
    {
        printf("%i\n",m%(int)pow(2,n));
    }
    else
    {
        printf("%i\n",m);
    }
    return 0;
}