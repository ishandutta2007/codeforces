#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    map<int,int> xd;
    long long suma=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        xd[a]=b;
        suma+=b;
    }
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        int vec=xd[a];
        if(vec==0||b>vec)
        {
            suma=suma+b-vec;
        }
    }
    printf("%lld",suma);
    return 0;
}