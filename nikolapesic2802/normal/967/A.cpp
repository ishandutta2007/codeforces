#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,s;
    scanf("%i %i",&n,&s);
    int niz[n];
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        niz[i]=a*60+b;
    }
    if(niz[0]>s)
    {
        printf("0 0");
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int d=niz[i]-niz[i-1];
        if(d>2*s+1)
        {
            int t=niz[i-1]+s+1;
            int a,b;
            b=t%60;
            a=t/60;
            printf("%i %i",a,b);
            return 0;
        }
    }
    int t=niz[n-1]+1+s;
    int a,b;
    b=t%60;
    a=t/60;
    printf("%i %i",a,b);
    return 0;
}