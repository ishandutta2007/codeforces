#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int gore[n],dole[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&gore[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&dole[i]);
    }
    long long ringG[n+1],ringD[n+1];
    ringG[n]=ringD[n]=0;
    long long zasada=0;
    long long zbir=0;
    int multi=2*n-2;
    int kolona=0;
    for(int i=n-1;i>=0;i--)
    {
        zasada-=zbir;
        zasada+=(long long)multi*(long long)gore[i]+(long long)(multi+kolona*2+1)*(long long)dole[i];
        zbir+=(long long)gore[i]+(long long)dole[i];
        ringG[i]=zasada;
        //printf("%i: %i\n",ringG[i]);
        kolona++;
        multi-=2;
    }
    zasada=0;
    zbir=0;
    multi=2*n-2;
    kolona=0;
    for(int i=n-1;i>=0;i--)
    {
        zasada-=zbir;
        zasada+=(long long)multi*(long long)dole[i]+(long long)(multi+kolona*2+1)*(long long)gore[i];
        zbir+=(long long)dole[i]+(long long)gore[i];
        ringD[i]=zasada;
        //printf("%i: %i\n",ringD[i]);
        kolona++;
        multi-=2;
    }
    long long maxx=ringG[0];
    //printf("%I64d\n",maxx);
    int tr=0;
    zbir=0;
    kolona=0;
    while(tr+4<=2*n)
    {
        zbir+=(long long)tr*(long long)gore[kolona];
        tr++;
        zbir+=(long long)tr*(long long)dole[kolona];
        kolona++;
        tr++;
        maxx=max(maxx,zbir+ringD[kolona]);
        //printf("%I64d\n",maxx);
        zbir+=(long long)tr*(long long)dole[kolona];
        tr++;
        zbir+=(long long)tr*(long long)gore[kolona];
        tr++;
        kolona++;
        maxx=max(maxx,zbir+ringG[kolona]);
        //printf("%I64d\n",maxx);
    }
    printf("%I64d\n",maxx);
    return 0;
}