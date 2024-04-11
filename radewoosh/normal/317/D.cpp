#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

long long n;
int v;
int ile[107];
int bylo[100007];
int wyn;
int nim[35];

int main()
{
nim[1]=1;
nim[2]=2;
nim[3]=1;
nim[4]=4;
nim[5]=3;
nim[6]=2;
nim[7]=1;
nim[8]=5;
nim[9]=6;
nim[10]=2;
nim[11]=1;
nim[12]=8;
nim[13]=7;
nim[14]=5;
nim[15]=9;
nim[16]=8;
nim[17]=7;
nim[18]=3;
nim[19]=4;
nim[20]=7;
nim[21]=4;
nim[22]=2;
nim[23]=1;
nim[24]=10;
nim[25]=9;
nim[26]=3;
nim[27]=6;
nim[28]=11;
nim[29]=12;
    scanf("%lld", &n);
    for (long long i=2; i*i<=n; i++)
    {
        if (bylo[i])
        continue;
        v=0;
        for (long long j=i; j<=n; j*=i)
        {
            v++;
            if (j*j<=n)
            bylo[j]=1;
        }
        ile[v]++;
        wyn+=v;
    }
    ile[1]+=n-wyn;
    wyn=0;
    for (int i=1; i<=29; i++)
    {
        wyn^=nim[i]*(ile[i]&1);
    }
    if (wyn)
    printf("Vasya");
    else
    printf("Petya");
    return 0;
}