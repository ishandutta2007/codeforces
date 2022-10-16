#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    int a;
    int tr=0,res=0;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&a);
        tr+=a;
        printf("%i ",tr/m);
        tr=tr%m;
    }

    return 0;
}