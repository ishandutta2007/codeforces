#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int niz[n];
    int krug[n];
    int koji;
    int minn=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        niz[i]-=i;
        niz[i]=max(niz[i],0);
        krug[i]=niz[i]/n;
       // printf("%i\n",krug[i]);
        if(niz[i]%n!=0)
        {
            krug[i]++;
        }
        //printf("%i\n",krug[i]);
        if(minn==-1||minn>krug[i])
        {
            koji=i+1;
            minn=krug[i];
        }
    }
    printf("%i\n",koji);
    return 0;
}